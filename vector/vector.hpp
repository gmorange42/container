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

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _arr(NULL), _alloc(alloc), _size(0), _capacity(0)
			{
				assign(n, val);
			}

			template <class InputIterator>
				vector (InputIterator first,
						InputIterator last, const allocator_type& alloc = allocator_type()) :
					_arr(NULL),
					_alloc(alloc),
					_size(0),
					_capacity(0)
			{
				assign(first, last);
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
					erase(begin(), end());
					insert(begin(), first, last);
//					if (static_cast<size_type>(last - first) > _capacity)
//						reserve(last - first);
//					else
//						clear();
//
//					for (;first != last; ++first)
//						push_back(*first);
				}

			void assign (size_type n, const value_type& val)
			{
				erase(begin(), end());
				insert(begin(), n, val);
//				if (n > _capacity || !_arr)
//					reserve(n);
//				else
//					clear();
//
//				for (size_type i = 0; i < n; ++i)
//					push_back(val);
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

				//std::cout << "HELLO 1 :  " << _size << ' ' << _capacity << std::endl;
				if (_size == _capacity)
				{
				//std::cout << "HELLO 2" << std::endl;
					if (_capacity != 0)
					{
				//std::cout << "HELLO 3" << std::endl;
						_capacity *= 2;
					}
					else
					{
				//std::cout << "HELLO 4" << std::endl;
						++_capacity;
					}
					ft_reallocate();
					position = begin() + to_add;
				}

				if (position == end())
				{
				//std::cout << "HELLO 5.1 :  " << _size << ' ' << _capacity << std::endl;
					push_back(val);
				//std::cout << "HELLO 5.2 :  " << _size << ' ' << _capacity << std::endl;
				}
				else
				{
				//std::cout << "HELLO 6" << std::endl;
					size_type	i = 0;
					value_type*	temp_arr = _alloc.allocate(_capacity + 1);
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
				//std::cout << "POUET 1" << std::endl;
							//std::cout << "SIZE : " << _size << " CAPACITY : " << _capacity << std::endl;
				if (_size + n > _capacity)
				{
				//std::cout << "POUET 2" << std::endl;
							//std::cout << "SIZE : " << _size << " CAPACITY : " << _capacity << std::endl;
					size_type	to_add = position - begin();
					if (_size + n > _capacity * 2)
					{
				//std::cout << "POUET 3" << std::endl;
							//std::cout << "SIZE : " << _size << " CAPACITY : " << _capacity << std::endl;
						reserve(_size + n);
							//std::cout << "SIZE : " << _size << " CAPACITY : " << _capacity << std::endl;
					}
					else
					{
				//std::cout << "POUET 4" << std::endl;
							//std::cout << "SIZE : " << _size << " CAPACITY : " << _capacity << std::endl;
						reserve(n);
							//std::cout << "SIZE : " << _size << " CAPACITY : " << _capacity << std::endl;
					}
					position = begin() + to_add;
				}
				for (size_type i = 0; i < n; ++i)
					position  = insert(position, val) + 1;
				//std::cout << "POUET 5" << std::endl;
			}

			template<class InputIterator>
				void	insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
				{
					std::cout << "HERE POUET " << &first << ' ' << &last << " SIZE : " << _size << " CAPACITY : " << _capacity << " &(*first) : " << &(*first) << " &(*last) : " << &(*last) << " &first : " << &first << " &last : " << &last  << std::endl;
					std::cout << "&(*last) = &(*first) : " << &(*last) - &(*first) << std::endl;
					std::cout << "&last) = &first : " << &first - &last << std::endl;
					if (&(*first) > &(*last))
					{
						std::cout << "HERE MAN, BEFORE THROW" << std::endl;
						throw (std::length_error("vector::_M_range_insert"));
					}
					if (_size + (&(*last) - &(*first)) > _capacity)
					{
						//std::cout << "HERE 1" << std::endl;
						size_type	to_add = position - begin();
						if (_size + (&(*last) - &(*first)) > _capacity * 2)
						{
							//std::cout << "HERE 2" << std::endl;
							//std::cout << "SIZE : " << _size << " CAPACITY : " << _capacity << std::endl;
							reserve (_size + (&(*last) - &(*first)));
							//std::cout << &last - &first  << &last << ' ' << &first << std::endl;
							//std::cout << "SIZE : " << _size << " CAPACITY : " << _capacity << std::endl;
						}
						else
						{
							//std::cout << "HERE 3" << std::endl;
							reserve(_size);
						}
						position = begin() + to_add;
					}
					for (; first != last; ++first)
						position = insert(position, *first) + 1;
				}

			iterator	erase(iterator position)
			{
				if (position == end() - 1)
				{
					pop_back();
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
					for (size_type i = &(*last) - &(*first); i > 0; --i)
						pop_back();
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

				std::cout << "BEFORE ALLOCATOR : " << _capacity << std::endl;
				new_arr = _alloc.allocate(_capacity);
					std::cout << "HERE DUDE, AFTER THE THROW CONDITION" << std::endl;

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
		bool	operator==(const vector<T, Alloc>& lhs, const vector <T, Alloc>& rhs)
		{
			typename ft::vector<T>::const_iterator	lhs_it = lhs.begin();
			typename ft::vector<T>::const_iterator	rhs_it = rhs.begin();

			while (lhs_it != lhs.end() && rhs_it != rhs.end())
			{
				if (*lhs_it == *rhs_it)
				{
					++lhs_it;
					++rhs_it;
				}
				else
					return (false);
			}
			if (lhs_it == lhs.end() && rhs_it == rhs.end())
				return (true);
			return (false);
		}

	template <class T, class Alloc>
		bool	operator!=(const vector<T, Alloc>& lhs, const vector <T, Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

	template <class T, class Alloc>
		bool	operator<(const vector<T, Alloc>& lhs, const vector <T, Alloc>& rhs)
		{
			return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template <class T, class Alloc>
		bool	operator<=(const vector<T, Alloc>& lhs, const vector <T, Alloc>& rhs)
		{
			return (operator==(lhs, rhs) || operator<(lhs, rhs));
		}

	template <class T, class Alloc>
		bool	operator>(const vector<T, Alloc>& lhs, const vector <T, Alloc>& rhs)
		{
			return ( !operator<(lhs, rhs) && !operator==(lhs, rhs));
		}

	template <class T, class Alloc>
		bool	operator>=(const vector<T, Alloc>& lhs, const vector <T, Alloc>& rhs)
		{
			return ( operator==(lhs, rhs) || operator>(lhs, rhs));
		}

	template <class T, class Alloc>
		void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
		{
			x.swap(y);
		}
}
#endif
