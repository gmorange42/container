#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "vector_iterator.hpp"

namespace ft
{
	template <class Iterator>
		class reverse_iterator
	{
		protected:
			Iterator current;
		public:
			typedef Iterator						iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename iterator_traits<Iterator>::reference		reference;
			typedef typename iterator_traits<Iterator>::pointer		pointer;

			reverse_iterator() {}

			explicit reverse_iterator(Iterator x) : current(x) {}

			template <class U>
				reverse_iterator(const reverse_iterator<U>& u) : current(u.base()) {}

			Iterator base() const
			{
				return (current);
			}

			reference operator*() const
			{
				Iterator tmp = current;
				return (*--tmp);
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			reverse_iterator& operator++()
			{
				--current;
				return (*this);
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--current;
				return (tmp);
			}

			reverse_iterator& operator--()
			{
				++current;
				return (*this);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++current;
				return (tmp);
			}

			reverse_iterator operator+ (difference_type n) const
			{
				return (reverse_iterator(current - n));
			}

			reverse_iterator& operator+=(difference_type n)
			{
				current -= n;
				return (*this);
			}

			reverse_iterator operator- (difference_type n) const
			{
				return (reverse_iterator(current + n));
			}

			reverse_iterator& operator-=(difference_type n)
			{
				current += n;
				return (*this);
			}

			reference operator[](difference_type n) const
			{
				return (current[-n -1]);
			}

			operator	reverse_iterator<Iterator const>(void) const
			{
				return (reverse_iterator<Iterator const>(current));
			}
	};
	template <class Iterator1, class Iterator2>
		bool operator==(
				const reverse_iterator<Iterator1>& x,
				const reverse_iterator<Iterator2>& y)
		{
			return (x.base() == y.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator<(
				const reverse_iterator<Iterator1>& x,
				const reverse_iterator<Iterator2>& y)
		{
			return (x.base() > y.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator!=(
				const reverse_iterator<Iterator1>& x,
				const reverse_iterator<Iterator2>& y)
		{
			return (x.base() != y.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator>(
				const reverse_iterator<Iterator1>& x,
				const reverse_iterator<Iterator2>& y)
		{
			return (x.base() < y.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator>=(
				const reverse_iterator<Iterator1>& x,
				const reverse_iterator<Iterator2>& y)
		{
			return (x.base() <= y.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator<=(
				const reverse_iterator<Iterator1>& x,
				const reverse_iterator<Iterator2>& y)
		{
			return (x.base() >= y.base());
		}

	template <class Iterator1, class Iterator2>
		typename reverse_iterator<Iterator1>::difference_type operator-(
				const reverse_iterator<Iterator1>& x,
				const reverse_iterator<Iterator2>& y)
		{
			return (y.base() - x.base());
		}

	template <class Iterator>
		reverse_iterator<Iterator> operator+(
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& x)
		{
			return (reverse_iterator<Iterator>(x.base() - n));
		}
}

#endif
