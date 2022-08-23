#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../iterator_traits/iterator_traits.hpp"

namespace ft
{
//	struct input_iterator_tag {};
//	struct output_iterator_tag {};
//	struct forward_iterator_tag : public input_iterator_tag {};
//	struct bidirectional_iterator_tag : public forward_iterator_tag {};
//	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

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

				VectorIterator& operator=(const VectorIterator& x)
				{
					this = x._ptr;
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

				reference	operator->(void) const
				{
					return  (&(*_ptr));
				}

				VectorIterator&	operator++(void)
				{
					++_ptr;
					return(*this);
				}

				VectorIterator&	operator++(int)
				{
					pointer	temp = *this;
					++_ptr;
					return(*this);
				}

				VectorIterator&	operator--(void)
				{
					--_ptr;
					return(*this);
				}

				VectorIterator&	operator--(int)
				{
					pointer	temp = *this;
					--_ptr;
					return(*this);
				}

				VectorIterator&	operator+(difference_type n) const
				{
					VectorIterator temp(_ptr + n)
					return (temp);
				}

				VectorIterator&	operator-(difference_type n) const
				{
					VectorIterator temp(_ptr - n)
					return (temp);
				}

				difference_type operator-(const VectorIterator & rhs) const
				{
					return (_ptr - rhs._ptr);
				}

				VectorIterator&	operator+=(difference_type n)
				{
					_ptr += n;
					return(*this);
				}

				VectorIterator&	operator-=(difference_type n)
				{
					_ptr -= n;
					return(*this);
				}

				reference	operator[](difference_type n) const
				{
					return (&(*_ptr + n));
				}
		};
}

#endif
