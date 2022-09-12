#ifndef	STACK_HPP
#define	STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
		class stack
		{
			public:
				typedef typename	Container::value_type	value_type;
				typedef typename	Container::size_type	size_type;
				typedef			Container		container_type;

				explicit stack (const container_type & ctnr = container_type()) : c(ctnr) {}
				stack(const stack& rhs) {*this = rhs;}
				stack&	operator=(const stack& rhs){c = rhs.c; return (*this);}
				~stack() {};

				bool			empty(void) const		{return c.empty();}
				size_type		size(void) const		{return c.size();}
				value_type&		top(void)			{return c.back();}
				const value_type&	top(void) const			{return c.back();}
				void			push(const value_type& x)	{return c.push_back(x);}
				void			pop(void)			{return c.pop_back();}
				Container const		getC(void) const		{return c;}

			protected:
				Container	c;
				template <class T1, class Container1> friend bool operator==(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
				template <class T1, class Container1> friend bool operator!=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
				template <class T1, class Container1> friend bool operator<(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
				template <class T1, class Container1> friend bool operator<=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
				template <class T1, class Container1> friend bool operator>(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
				template <class T1, class Container1> friend bool operator>=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
		};

	template <class T1, class Container1>
		bool	operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1> & rhs) {
			return(lhs.c == rhs.c);
		}

	template <class T1, class Container1>
		bool	operator!=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs) {
			return(!(lhs == rhs));
		}

	template <class T1, class Container1>
		bool	operator<(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs) {
			return(lhs.c < rhs.c);
		}

	template <class T1, class Container1>
		bool	operator<=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs) {
			return(!(lhs > rhs));
		}

	template <class T1, class Container1>
		bool	operator>(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs) {
			return(lhs.c > rhs.c);
		}

	template <class T1, class Container1>
		bool	operator>=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs) {
			return(!(lhs < rhs));
		}
}

#endif
