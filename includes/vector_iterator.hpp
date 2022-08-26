#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class T>
		class	VectorIterator
		{
			public:
				typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;
				typedef typename ft::iterator_traits<T*>::value_type		value_type;
				typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
				typedef typename ft::iterator_traits<T*>::pointer		pointer;
				typedef typename ft::iterator_traits<T*>::reference		reference;

			private:
				pointer	_ptr;

			public:
				VectorIterator() : _ptr(NULL) {};

				VectorIterator(const VectorIterator & x) : _ptr(x._ptr) {}

				VectorIterator(pointer x) : _ptr(x) {}

				VectorIterator& operator=(const VectorIterator x)
				{
					_ptr = x._ptr;
					return (*this);
				}

				virtual	~VectorIterator(void) {}


				pointer	base() const
				{
					return (_ptr);
				}

				reference	operator*(void) const
				{
					return (*_ptr);
				}

				pointer	operator->(void) const
				{
					return  (_ptr);
				}

				VectorIterator&	operator++(void)
				{
					++_ptr;
					return(*this);
				}

				VectorIterator	operator++(int)
				{
					VectorIterator	temp(*this);
					++_ptr;
					return(temp);
				}

				VectorIterator&	operator--(void)
				{
					--_ptr;
					return(*this);
				}

				VectorIterator	operator--(int)
				{
					VectorIterator	temp(*this);
					--_ptr;
					return(temp);
				}

				VectorIterator	operator+(const difference_type n) const
				{
					VectorIterator temp(_ptr + n);
					return (temp);
				}

				VectorIterator	operator-(const difference_type n) const
				{
					VectorIterator temp(_ptr - n);
					return (temp);
				}

				difference_type operator-(const VectorIterator & rhs) const
				{
					return (_ptr - rhs._ptr);
				}

				VectorIterator&	operator+=(const difference_type n)
				{
					_ptr += n;
					return(*this);
				}

				VectorIterator&	operator-=(const difference_type n)
				{
					_ptr -= n;
					return(*this);
				}

				reference	operator[](const difference_type n) const
				{
					return (_ptr[n]);
				}

				operator	VectorIterator<const T>(void) const
				{
					return (VectorIterator<const T>(_ptr));
				}

		};
	
	template <class T, class U>
		bool	operator==(const VectorIterator<T> & lhs, const VectorIterator<U> & rhs)
		{
			return (lhs.base() == rhs.base());
		}
	
	template <class T, class U>
		bool	operator!=(const VectorIterator<T> & lhs, const VectorIterator<U> & rhs)
		{
			return (lhs.base() != rhs.base());
		}
	
	template <class T, class U>
		bool	operator<(const VectorIterator<T> & lhs, const VectorIterator<U> & rhs)
		{
			return (lhs.base() < rhs.base());
		}
	
	template <class T, class U>
		bool	operator>(const VectorIterator<T> & lhs, const VectorIterator<U> & rhs)
		{
			return (lhs.base() > rhs.base());
		}
	
	template <class T, class U>
		bool	operator<=(const VectorIterator<T> & lhs, const VectorIterator<U> & rhs)
		{
			return (lhs.base() <= rhs.base());
		}
	
	template <class T, class U>
		bool	operator>=(const VectorIterator<T> & lhs, const VectorIterator<U> & rhs)
		{
			return (lhs.base() >= rhs.base());
		}

	template <class T>
		VectorIterator<T>	operator+(const typename VectorIterator<T>::difference_type n, const VectorIterator<T> & rhs)
		{
			return (rhs.base() + n);
		}

	template <class T, class U>
		typename VectorIterator<T>::difference_type		operator-(const VectorIterator<T> & rhs, const VectorIterator<U> & lhs)
		{
			return (rhs.base() - lhs.base());
		}
}

#endif
