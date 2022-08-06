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
				_arr = _alloc.allocate(n);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_arr + i, val);
			}

			template <class InputIterator>
				vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
						InputIterator last, const allocator_type& alloc = allocator_type()) :
					_alloc(alloc),
					_size(last - first),
					_capacity(_size)
			{
				_arr = _alloc.allocate(_size);
				int i = 0;
				while (first != last)
				{
					_alloc.construct(_arr + i, *first);
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
				_size = x._size;
				_capacity = x._capacity;
				_alloc = x._alloc;
				_arr = _alloc.allocate(_capacity);
				for (size_t i = 0; i < _size; ++i)
				{
					_alloc.construct(_arr + i, x._arr[i]);
				}

				return (*this);
			}

			//----------------------DESTRUCTOR----------------------

			~vector()
			{
				for (size_type i = 0; i < _size && i < _capacity; ++i)
					_alloc.destroy(_arr + i);
				_alloc.deallocate(_arr, _size);
			}

			//---------------------ITERATORS----------------------

			iterator	begin(void)
			{
				iterator	it(_arr);
				return (it);
			}

			const_iterator	begin(void) const
			{
				const_iterator	it(_arr);
				return (it);
			}

			iterator	end(void)
			{
				iterator	it(_arr + _size);
				return (it);
			}

			const_iterator	end(void) const
			{
				const_iterator	it(_arr + _size);
				return (it);
			}

			reverse_iterator rbegin(void)
			{
				reverse_iterator	it(end());
				return (it);
			}

			const_reverse_iterator rbegin(void) const
			{
				const_reverse_iterator	it(end());
				return (it);
			}

			reverse_iterator rend(void)
			{
				reverse_iterator	it(begin());
				return (it);
			}

			const_reverse_iterator rend(void) const
			{
				const_reverse_iterator	it(begin());
				return (it);
			}

			//----------------------CAPACITY----------------------

			size_type	size(void) const
			{
				return (_size);
			}

			size_type	max_size(void) const
			{
				return (_alloc.max_size());
			}

			void		resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_type i = n; i < _size; ++i)
						_alloc.destroy(_arr + i);
					_size = n;
				}
				if (n >= _size)
				{
					if (n >= _capacity)
					{
						_capacity = n;
						ft_reallocate();
					}
					for (size_type i = _size; i < n; ++i)
						push_back(val);
				}
			}

			size_type	capacity(void) const
			{
				return (_capacity);
			}

			bool		empty(void) const
			{
				return (_size == 0);
			}

			void		reserve(size_type n)
			{
				if (n > _capacity)
				{
					_capacity = n;
					ft_reallocate();
				}
			}

			//----------------------ELEMENT_ACCESS----------------------

			reference	operator[](size_type n)
			{
				return (_arr[n]);
			}

			const_reference	operator[](size_type n) const
			{
				return (_arr[n]);
			}

			reference	at(size_type n)
			{
				if (n >= _size)
					throw (std::out_of_range("vector:: n >= size()"));
				return (_arr[n]);
			}

			const_reference	at(size_type n) const
			{
				if (n >= _size)
					throw (std::out_of_range("vector:: n >= size()"));
				return (_arr[n]);
			}

			reference	front(void)
			{
				return (_arr[0]);
			}

			const_reference	front(void) const
			{
				return (_arr[0]);
			}

			reference	back(void)
			{
				return (_arr[_size - 1]);
			}

			const_reference	back(void) const
			{
				return (_arr[_size - 1]);
			}

			//----------------------MODIFIERS----------------------


			template<class InputIterator>
				void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
				{
					if (last - first > _capacity)
						reserve(last - first);
					else
						clear();

					for (;first != last; ++first)
						push_back(*first);
				}

			void assign (size_type n, const value_type& val)
			{
				if (n > _capacity)
					reserve(n);
				else
					clear();

				for (size_type i = 0; i < n; ++i)
					push_back(val);
			}

			void	push_back(const value_type& val)
			{
				if (_capacity == 0)
				{
					++_capacity;
					_arr = _alloc.allocate(_capacity);
					_alloc.construct(_arr, val);
				}
				else if (_size == _capacity)
				{
					_capacity *= 2;

					ft_reallocate();

					_alloc.construct(_arr+ _size, val);
				}
				else
				{
					if (_size < _capacity)
						_alloc.construct(_arr + _size, val);
				}
				++_size;
			}

			void	pop_back(void)
			{
				--_size;
				_alloc.destroy(_arr + _size);
			}

			iterator	insert (iterator position, const value_type& val)
			{
				size_type	to_add = position - begin();

				if (_size == _capacity)
				{
					if (_capacity != 0)
						_capacity *= 2;
					else
						++_capacity;
					ft_reallocate();
					position = begin() + to_add;
				}

				if (position == end())
					push_back(val);
				else
				{
					size_type	i = 0;
					value_type*	temp_arr = _alloc.allocate(_capacity + 1);
					iterator it = begin();
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

			void		insert (iterator position, size_type n, const value_type& val)
			{
				if (_size + n > _capacity)
				{
					size_type	to_add = position - begin();
					if (_size + n > _capacity * 2)
						reserve(_size + n);
					else
						reserve(_size * 2);
					position = begin() + to_add;
				}
				for (size_type i = 0; i < n; ++i)
					position  = insert(position, val) + 1;
			}

			template<class InputIterator>
				void	insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
				{
					if (first > last)
						throw (std::length_error("vector::_M_range_insert"));
					if (_size + (last - first) > _capacity)
					{
						size_type	to_add = position - begin();
						if (_size + (last - first) > _capacity * 2)
							reserve (_size + (last - first));
						else
							reserve(_size * 2);
						position = begin() + to_add;
					}
					for (; first < last; ++first)
						position = insert(position, *first) + 1;
				}

			iterator	erase(iterator position)
			{
				if (position == end() - 1)
				{
					_alloc.destroy(&position);
					--_size;
					return(position);
				}
				else
				{
					size_type i = 0;
					size_type to_ret = position - begin();
					value_type*	temp_arr = _alloc.allocate(_capacity);
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
					_alloc.deallocate(_arr, _size);
					_size = i;
					_arr = temp_arr;
					return(begin() + to_ret);
				}
			}

			iterator	erase(iterator first, iterator last)
			{
				if (last == end())
				{
					_size -= last - first;
					for (const_iterator it = begin(); it < end(); ++it)
					{
						_alloc.destroy(&it);
					}
					return (end());
				}
				else
				{
					size_type	ret = first - begin();
					size_type	i = 0;
					value_type*	temp_arr = _alloc.allocate(_capacity);

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
					_alloc.deallocate(_arr, _size);
					_size = i;
					_arr = temp_arr;
					return (begin() + ret);
				}
			}

			void	swap(vector<value_type> & rhs)
			{
				pointer 	temp_arr = _arr;
				size_type	temp_size = _size;
				size_type	temp_capacity = _capacity;

				_arr = rhs._arr;
				_size = rhs._size;
				_capacity = rhs._capacity;

				rhs._arr = temp_arr;
				rhs._size = temp_size;
				rhs._capacity = temp_capacity;
			}

			void	clear(void)
			{
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_arr + i);
				_size = 0;
			}


			//----------------------ALLOCATOR----------------------

			allocator_type	get_allocator() const
			{
				return (allocator_type());
			}


			//----------------------OTHER----------------------
			

			private:

			void	ft_reallocate(void)
			{
				value_type*	new_arr;

				new_arr = _alloc.allocate(_capacity);

				for (size_type i = 0; i < _size; ++i)
				{
					_alloc.construct(new_arr + i, _arr[i]);
					_alloc.destroy(_arr + i);
				}

				_alloc.deallocate(_arr, _size);

				_arr = new_arr;
			}
		};
	template <class T, class Alloc>
		void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
		{
			x.swap(y);
		}
}
#endif
