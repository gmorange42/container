#ifndef	STACK_HPP
#define	STACK_HPP

#include <iostream>
#include <vector>

namespace ft
{
	template <class T, class Container = std::vector<T> >
	class stack
	{
		public:
		explicit stack (const Container & ctnr = Container()) : c(ctnr) {}

		typedef typename	Container::value_type	value_type;
		typedef typename	Container::size_type	size_type;
		typedef			Container		container_type;

		bool			empty(void) const		{return c.empty();}
		size_type		size(void) const		{return c.size();}
		value_type&		top(void)			{return c.back();}
		const value_type&	top(void) const			{return c.back();}
		void			push(const value_type& x)	{return c.push_back(x);}
		void			pop(void)			{return c.pop_back();}
		Container const		getC(void) const		{return c;}

		protected:
		Container	c;
	};

	template <class T, class Container>
		bool	operator==(const stack<T, Container>& lhs, const stack<T, Container> & rhs) {
			return(lhs.getC() == rhs.getC());
		}

	template <class T, class Container>
		bool	operator!=(const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
			return(!(lhs == rhs));
		}

	template <class T, class Container>
		bool	operator<(const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
			return(lhs.getC() < rhs.getC());
		}

	template <class T, class Container>
		bool	operator<=(const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
			return(!(lhs > rhs));
		}

	template <class T, class Container>
		bool	operator>(const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
			return(lhs.getC() > rhs.getC());
		}

	template <class T, class Container>
		bool	operator>=(const stack<T, Container> & lhs, const stack<T, Container> & rhs) {
			return(!(lhs < rhs));
		}
}

#endif
