#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include "../is_integral/is_integral.hpp"
#include "../enable_if/enable_if.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
		class	vector 
		{
			public:
			typedef T						value_type;
			typedef Alloc                                           allocator_type;
			typedef typename allocator_type::reference              reference;
			typedef typename allocator_type::const_reference        const_reference;
			typedef typename allocator_type::pointer                pointer;
			typedef typename allocator_type::const_pointer          const_pointer;
//			typedef typename std::random_access_iterator_tag        iterator;
//			typedef typename std::random_access_iterator_tag        const const_iterator;
			typedef typename std::vector<T>::iterator	        iterator;
			typedef typename std::vector<T>::const_iterator         const_iterator;
			typedef typename std::reverse_iterator<iterator>        reverse_iterator;
			typedef typename std::reverse_iterator<const_iterator>  const_reverse_iterator;
			typedef std::ptrdiff_t                                  difference_type;
			typedef size_t                                          size_type;

			public:
			value_type*	_arr;
			allocator_type	_alloc;
			size_type	_size;
			size_type	_capacity;

			//	pointer		_begin;
			//	pointer		_end;
			//	pointer		_capacity;
			
			//	size_type	size(void) const
			//	{
			//		return (_end - _begin);
			//	}
			//	size_type	capacity(void) const
			//	{
			//		return (_capacity - _begin);
			//	}
			//	bool		empty(void) const
			//	{
			//		return (_begin == _end);
			//	}


			//----------------------CONTRUCTORS----------------------

			explicit vector(const allocator_type& alloc = allocator_type()) : _arr(0), _alloc(alloc), _size(0), _capacity(0) {}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n)
			{
				this->_arr = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_size; ++i)
					this->_alloc.construct(this->_arr + i, val);
			}

			template <class InputIterator>
				vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
						InputIterator last, const allocator_type& alloc = allocator_type()) :
					_alloc(alloc),
					_size(last - first),
					_capacity(_size)
			{
				this->_arr = this->_alloc.allocate(this->_size);
				int i = 0;
				while (first != last)
				{
					this->_alloc.construct(this->_arr + i, *first);
					++first;
					++i;
				}
			}

			vector(const vector& x)
			{
				*this = x;
			}

			vector&	operator=(const vector& x)
			{
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_alloc = x._alloc;
				this->_arr = _alloc.allocate(this->_capacity);
				for (size_t i = 0; i < this->_size; ++i)
				{
					this->_alloc.construct(this->_arr + i, x._arr[i]);
				}

				return (*this);
			}

			//----------------------DESTRUCTOR----------------------

			~vector()
			{
				for (size_type i = 0; i < this->_size && i < this->_capacity; ++i)
					_alloc.destroy(this->_arr + i);
				_alloc.deallocate(_arr, _size);
			}

			//----------------------CAPACITY----------------------

			size_type	size(void) const
			{
				return (this->_size);
			}

			size_type	max_size(void) const
			{
				return (this->_alloc.max_size());
			}

			size_type	capacity(void) const
			{
				return (this->_capacity);
			}

			void		resize(size_type n, value_type val = value_type())
			{
				if (n < this->_size)
				{
					for (size_type i = n; i < this->_size; ++i)
						_alloc.destroy(this->_arr + i);
					this->_size = n;
				}
				if (n >= this->_size)
				{
					if (n >= this->_capacity)
					{
						this->_capacity = n;
						ft_reallocate();
					}
					for (size_type i = this->_size; i < n; ++i)
						this->push_back(val);
				}
			}

			bool		empty(void) const
			{
				return (this->_size == 0);
			}

			void		reserve(size_type n)
			{
				if (n > this->_capacity)
				{
					this->_capacity = n;
					ft_reallocate();
				}
			}

			//----------------------MODIFIERS----------------------


			template<class InputIterator>
				void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
				{
					if (last - first > this->_capacity)
						reserve(last - first);
					else
						clear();

					for (;first != last; ++first)
						push_back(*first);
				}

			void assign (size_type n, const value_type& val)
			{
				if (n > this->_capacity)
					reserve(n);
				else
					clear();

				for (size_type i = 0; i < n; ++i)
					push_back(val);
			}

			void	push_back(value_type elem)
			{
				if (this->_capacity == 0)
				{
					++this->_capacity;
					this->_arr = _alloc.allocate(this->_capacity);
					this->_alloc.construct(this->_arr, elem);
				}
				else if (_size == this->_capacity)
				{
					this->_capacity *= 2;

					ft_reallocate();

					this->_alloc.construct(this->_arr+ this->_size, elem);
				}
				else
				{
					if (this->_size < this->_capacity)
						_alloc.construct(this->_arr + this->_size, elem);
				}
				++this->_size;
			}

			void	pop_back(void)
			{
				--this->_size;
				_alloc.destroy(this->_arr + this->_size);
			}

			iterator	insert (iterator position, const value_type& val)
			{
				size_type	to_add = position - begin();

				if (_size == _capacity || position == end())
				{
					_capacity *= 2;
					ft_reallocate();
					position = begin() + to_add;
				}

				if (position == end())
				{
					_alloc.construct(this->_arr + this->_size, val);
					++_size;
				}
				else
				{
					size_type	i = 0;
					value_type*	temp_arr = _alloc.allocate(this->_capacity + 1);
					for (iterator it = begin(); it < position; ++it)
					{
						_alloc.construct(temp_arr + i, *it);
						++i;
					}

					_alloc.construct(temp_arr + i++, val);

					for (iterator it = position; it < end(); ++it)
					{
						_alloc.construct(temp_arr + i, *it);
						++i;
					}
					clear();
					_alloc.deallocate(_arr, _size);
					_arr = temp_arr;
					position = begin() + to_add;
					_size = i;
				}
				return (position);
			}

			void		insert (iterator position, size_type n, const value_type& val);

			template<class InputIterator>
				void	insert (iterator position, InputIterator first, InputIterator last);

			iterator	erase(iterator position)
			{
				if (position == end() - 1)
				{
					this->_alloc.destroy(&position);
					--this->_size;
					return(position);
				}
				else
				{
					size_type i = 0;
					size_type to_ret = position - begin();
					value_type*	temp_arr = _alloc.allocate(this->_capacity);
					const_iterator it = begin();
					for (; it < end(); ++it)
					{
						if (it != position)
						{
							_alloc.construct(temp_arr + i, *it);
							++i;
						}
					}
					clear();
					this->_alloc.deallocate(this->_arr, this->_size);
					_size = i;
					this->_arr = temp_arr;
					return(begin() + to_ret);
				}
			}

			iterator	erase(iterator first, iterator last)
			{
				if (last == end())
				{
					this->_size -= last - first;
					for (const_iterator it = begin(); it < end(); ++it)
					{
						this->_alloc.destroy(&it);
					}
					return (end() + 1);
				}
				else
				{
					size_type	ret = first - begin();
					size_type	i = 0;
					value_type*	temp_arr = _alloc.allocate(this->_capacity);

					for (iterator it = begin(); it < first; ++it)
					{
						_alloc.construct(temp_arr + i, *it);
						++i;
					}
					for (iterator it = last; it < end(); ++it)
					{
						_alloc.construct(temp_arr + i, *it);
						++i;
					}

					clear();
					this->_alloc.deallocate(this->_arr, this->_size);
					_size = i;
					this->_arr = temp_arr;
					return (begin() + ret);
				}
			}

			void	swap(vector<value_type> & rhs)
			{
				value_type*	temp__arr = _alloc.allocate(this->_capacity);
				int	temp__size = this->_size;
				int	temp__capacity = this->_capacity;
				for (size_type i = 0; i < this->_size; ++i)
				{
					_alloc.construct(temp__arr + i, this->_arr[i]);
					_alloc.destroy(this->_arr + i);
				}
				_alloc.deallocate(this->_arr, this->_size);
				this->_arr = rhs._arr;
				this->_size = rhs._size;
				this->_capacity = rhs._capacity;
				rhs._arr = temp__arr;
				rhs._size = temp__size;
				rhs._capacity = temp__capacity;

				/*
				pointer	tmp;

				tmp_arr = _arr;
				tmp_end = _end;
				tmp_cpct = _cpct;
				_arr = rhs._arr;
				_end = rhs._end;
				_cpct = rhs._cpct;
				rhs._arr = tmp_arr;
				rhs._end = tmp_end;
				rhs._cpct = tmp_cpct;

				pareil pour size
				pareil pour capacity
				*/
			}

			void	clear(void)
			{
				for (size_type i = 0; i < this->_size; ++i)
					this->_alloc.destroy(_arr + i);
				this->_size = 0;
			}

			//----------------------OPERATORS----------------------

			reference	operator[](size_type n)
			{
				return (this->_arr[n]);
			}

			const_reference	operator[](size_type n) const
			{
				return (this->_arr[n]);
			}

			reference	at(size_type n)
			{
				if (n >= this->_size)
					throw (std::out_of_range("vector:: n >= this->size()"));
				return (this->_arr[n]);
			}

			const_reference	at(size_type n) const
			{
				if (n >= this->_size)
					throw (std::out_of_range("vector:: n >= this->size()"));
				return (this->_arr[n]);
			}

			reference	front(void)
			{
				return (this->_arr[0]);
			}

			const_reference	front(void) const
			{
				return (this->_arr[0]);
			}

			reference	back(void)
			{
				return (this->_arr[this->_size - 1]);
			}

			const_reference	back(void) const
			{
				return (this->_arr[this->_size - 1]);
			}

			//---------------------ITERATORS----------------------

			iterator	begin(void)
			{
				iterator	it(_arr);
				return (it);
			}
			iterator	end(void)
			{
				iterator	it(_arr + _size);
				return (it);
			}

			reverse_iterator rbegin(void)
			{
				reverse_iterator	it(this->end());
				return (it);
			}

			reverse_iterator rend(void)
			{
				reverse_iterator	it(this->begin());
				return (it);
			}

			private:

			void	ft_reallocate(void)
			{
				value_type*	new_arr;

				new_arr = this->_alloc.allocate(this->_capacity);

				for (size_type i = 0; i < this->_size; ++i)
				{
					this->_alloc.construct(new_arr + i, this->_arr[i]);
					this->_alloc.destroy(this->_arr + i);
				}

				this->_alloc.deallocate(this->_arr, this->_size);

				this->_arr = new_arr;
			}
		};
}
#endif
