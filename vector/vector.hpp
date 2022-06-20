#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
		class	vector 
		{
			typedef T						value_type;
			typedef Alloc                                           allocator_type;
			typedef typename allocator_type::reference              reference;
			typedef typename allocator_type::const_reference        const_reference;
			typedef typename allocator_type::pointer                pointer;
			typedef typename allocator_type::const_pointer          const_pointer;
			typedef typename std::random_access_iterator_tag        iterator;
			typedef typename std::random_access_iterator_tag        const const_iterator;
			typedef typename std::reverse_iterator<iterator>        reverse_iterator;
			typedef typename std::reverse_iterator<const_iterator>  const_reverse_iterator;
			typedef std::ptrdiff_t                                  difference_type;
			typedef size_t                                          size_type;

			public:
			value_type*	_arr;
			Alloc		_alloc;
			size_type	_size;
			size_type	_capacity;


//----------------------CONTRUCTORS----------------------

			explicit vector(const allocator_type& alloc = allocator_type()) : _arr(0), _alloc(alloc), _size(0), _capacity(0) {}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n)
			{
				this->_alloc = alloc;
				this->_arr = this->_alloc.allocate(n);
				for (size_type i = 0; i < this->_size; ++i)
					this->_alloc.construct(this->_arr + i, val);
			}

/*to implement*/
			template <class InputIterator>
				vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

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
				(void) val;
			}

//----------------------MODIFIERS----------------------

			void	swap(vector<value_type> & rhs)
			{
				value_type*	temp__arr = _alloc.allocate(this->_capacity);
				int	temp__size = this->_size;
				int	temp__capacity = this->_capacity;
				for (size_type i = 0; i < this->size(); ++i)
					_alloc.construct(temp__arr + i, this->_arr[i]);
				for (size_type i = 0; i < this->_size; ++i)
					_alloc.destroy(this->_arr + i);
				_alloc.deallocate(this->_arr, this->_size);
				this->_arr = rhs._arr;
				this->_size = rhs._size;
				this->_capacity = rhs._capacity;
				rhs._arr = temp__arr;
				rhs._size = temp__size;
				rhs._capacity = temp__capacity;
			}

			void	push_back(value_type elem)
			{
				if (_capacity == 0)
				{
					++_capacity;
					this->_arr = _alloc.allocate(_capacity);
					_alloc.construct(this->_arr, elem);
				}
				else if (_size == _capacity)
				{
					this->_capacity *= 2;
					value_type*	new__arr;

					new__arr = this->_alloc.allocate(this->_capacity);
					for (size_type i = 0; i < this->_size; ++i)
						_alloc.construct(new__arr + i, this->_arr[i]);
					_alloc.construct(new__arr + this->_size, elem);
					
					for (size_type i = 0; i < this->_size; ++i)
						this->_alloc.destroy(this->_arr + i);
					this->_alloc.deallocate(this->_arr, this->_size);

					this->_arr = new__arr;
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
		};
}
#endif
