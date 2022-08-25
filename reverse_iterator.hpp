#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "../iterator/iterator.hpp"

namespace ft
{
	template <class Iterator>
		class reverse_iterator
		{
			typedef	Iterator						iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type		value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer		pointer;
			typedef typename ft::iterator_traits<Iter>::reference		reference;

			public:
			reverse_iterator(void) : _iter(NULL);

			explicit reverse_iterator(iterator_type it) : _iter(it)

			template <class Iter>
				reverse_iterator(const reverse_iterator<Iter> & ret_it) : _iter(rev_it.base());

			iterator_type	base(void) const
			{
				return (_iter);
			}

			reference	operator*(void) const
			{
				iterator_type	temp = _iter - 1;
				//iterator_type	temp = _iter;
				//--temp;
				return (*temp);
			}

			reverse_iterator	operator+(difference_type n) const
			{
				reverse_iterator	temp(_iter - n);
//				reverse_iterator	temp(_iter);
//				temp -= n;
				return (temp);
			}

			reverse_iterator&	operator++(void)
			{
				--_iter;
				return (*this);
			}

			reverse_iterator	operator++(int) // SI PROBLEME PRENDRE  CODE SUR https://cplusplus.com/reference/iterator/reverse_iterator/operator++/
			{
				iterator_type	temp = _iter;
				--_iter;
				return (temp);
			}

			reverse_iterator&	operator-=(difference_type n)
			{
				_iter -= n;
				return (*this);
			}

			reverse_iterator	operator-(difference_type n) const
			{
				reverse_iterator	temp(_iter + n);
//				reverse_iterator	temp(_iter);
//				temp += n;
				return (temp);
			}

			reverse_iterator&	operator--(void)
			{
				++_iter;
				return (*this);
			}

			reverse_iterator	operator--(int) // SI PROBLEME PRENDRE  CODE SUR https://cplusplus.com/reference/iterator/reverse_iterator/operator--/
			{
				iterator_type	temp = _iter;
				++_iter;
				return (temp);
			}

			reverse_iterator&	operator-=(difference_type n)
			{
				_iter += n;
				return (*this);
			}

			pointer	operator->(void) const https://cplusplus.com/reference/iterator/reverse_iterator/operator-%3E/
			{
				return (_iter);
			}

			reference	operator[](difference_type n) const
			{
				return (base()[-n -1]);
			}

			private:
			iterator_type	_iter;
		};

//	template <class Iterator>
//		bool	operator==(const reverse_iterator<Iterator>& lhs,
//				const reverse_iterator<Iterator>& rhs)
//		{
//			return (lhs.base() == rhs.base());
//		}

	template <class Iterator1, class Iterator2>
		bool	operator==(const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() == rhs.base());
		}

//	template <class Iterator>
//		bool	operator!=(const reverse_iterator<Iterator>& lhs,
//				const reverse_iterator<Iterator>& rhs)
//		{
//			return (lhs.base() != rhs.base());
//		}

	template <class Iterator1, class Iterator2>
		bool	operator!=(const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() != rhs.base());
		}

//	template <class Iterator>
//		bool	operator<(const reverse_iterator<Iterator>& lhs,
//				const reverse_iterator<Iterator>& rhs)
//		{
//			return (lhs.base() < rhs.base());
//		}

	template <class Iterator1, class Iterator2>
		bool	operator<(const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() < rhs.base());
		}

//	template <class Iterator>
//		bool	operator<=(const reverse_iterator<Iterator>& lhs,
//				const reverse_iterator<Iterator>& rhs)
//		{
//			return (lhs.base() <= rhs.base());
//		}

	template <class Iterator1, class Iterator2>
		bool	operator<=(const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() <= rhs.base());
		}

//	template <class Iterator>
//		bool	operator>(const reverse_iterator<Iterator>& lhs,
//				const reverse_iterator<Iterator>& rhs)
//		{
//			return (lhs.base() > rhs.base());
//		}

	template <class Iterator1, class Iterator2>
		bool	operator>(const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() > rhs.base());
		}

//	template <class Iterator>
//		bool	operator>=(const reverse_iterator<Iterator>& lhs,
//				const reverse_iterator<Iterator>& rhs)
//		{
//			return (lhs.base() >= rhs.base());
//		}

	template <class Iterator1, class Iterator2>
		bool	operator>=(const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() >= rhs.base());
		}

	template <class Iterator>
		reverse_iterator<Iterator>	operator*(
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& ret_it)
		{
			return (ret_it.base() + n);
		}

	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(
				const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs)
		{
			return(lhs.base() - rhs.base());
		}
}

#endif
