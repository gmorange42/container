#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
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
			value_type* arr;
			Alloc alloc;
			size_type	curent_size;
			size_type	curent_capacity;

			explicit vector(const allocator_type& alloc = allocator_type()) : arr(0), curent_size(0), curent_capacity(0) {}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : curent_size(n), curent_capacity(n)
			{
				this->arr = this->alloc.allocate(n);
				for (int i = 0; i < this->curent_size; ++i)
					this->alloc.construct(this->arr + i, val);
			}

			~vector()
			{
				for (int i = 0; i < this->curent_size && i < this->curent_capacity; ++i)
					alloc.destroy(this->arr + i);
				alloc.deallocate(arr, curent_size);
			}

			void	swap(vector<value_type> & rhs)
			{
				value_type*	temp_arr = alloc.allocate(this->curent_capacity);
				int	temp_curent_size = this->curent_size;
				int	temp_curent_capacity = this->curent_capacity;
				for (int i = 0; i < this->size(); ++i)
					alloc.construct(temp_arr + i, this->arr[i]);
				for (int i = 0; i < this->curent_size; ++i)
					alloc.destroy(this->arr + i);
				alloc.deallocate(this->arr, this->curent_size);
				this->arr = rhs.arr;
				this->curent_size = rhs.curent_size;
				this->curent_capacity = rhs.curent_capacity;
				rhs.arr = temp_arr;
				rhs.curent_size = temp_curent_size;
				rhs.curent_capacity = temp_curent_capacity;
			}

			void	push_back(value_type elem)
			{
				if (curent_capacity == 0)
				{
					++curent_capacity;
					this->arr = alloc.allocate(curent_capacity);
				}
				else if (curent_size == curent_capacity)
				{
					this->curent_capacity *= 2;
					value_type*	new_arr;

					new_arr = this->alloc.allocate(this->curent_capacity);
					for (int i = 0; i < this->curent_size; ++i)
						alloc.construct(new_arr + i, this->arr[i]);
					alloc.construct(new_arr + this->curent_size, elem);
					
					for (int i = 0; i < this->curent_size; ++i)
						this->alloc.destroy(this->arr + i);
					this->alloc.deallocate(this->arr, this->curent_size);

					this->arr = new_arr;
				}
				else
				{
					if (this->curent_size < this->curent_capacity)
						alloc.construct(this->arr + this->curent_size, elem);
				}
				++this->curent_size;
			}

			void	pop_back(void)
			{
				--this->curent_size;
				alloc.destroy(this->arr + this->curent_size);
			}

			size_t	size(void)
			{
				return (this->curent_size);
			}

			size_t	capacity(void)
			{
				return (this->curent_capacity);
			}

			value_type	operator[](int i)
			{
				return (this->arr[i]);
			}
		};
}
#endif
