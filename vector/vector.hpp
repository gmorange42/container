#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>

namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
		class vector
		{
			typedef T						value_type;
			typedef Alloc						allocator_type;
			typedef typename allocator_type::reference		reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer		pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename std::random_access_iterator_tag	iterator;
			typedef typename std::random_access_iterator_tag	const const_iterator;
			typedef typename std::reverse_iterator<iterator>	reverse_iterator;
			typedef typename std::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t					difference_type;
			typedef size_t						size_type;

			public:
			explicit vector (const allocator_type & alloc = allocator_type()) {}

			explicit vector (size_type n, const value_type & val = value_type(),
					const allocator_type & alloc = allocator_type());

			template <class InputIterator>
				vector (InputIterator first, InputIterator last,
						const allocator_type & alloc = allocator_type());

			vector (const vector & x);
		};
}

#endif
