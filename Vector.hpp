#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "VectorIterator.hpp"
namespace ft {
    template <class T, class Alloc = std::allocator<T>>
    class vector {
        private:
            allocator_type _vector;
            pointer _vector;
            size_type _size;
        public:
        //Member types
        // value_type	The first template parameter (T)
            typedef T value_type;
        // allocator_type	The second template parameter (Alloc)	defaults to: allocator<value_type>
            typedef Alloc allocator_type;
        // reference	allocator_type::reference	for the default allocator: value_type&
            typedef allocator_type::reference& reference; 
        // const_reference	allocator_type::const_reference	for the default allocator: const value_type&
            typedef allocator_type::const_reference& const_reference; 
        // pointer	allocator_type::pointer	for the default allocator: value_type*
            typedef allocator_type::pointer* pointer; 
        // const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*
            typedef allocator_type::const_pointer* const_pointer; 
        // iterator	a random access iterator to value_type	convertible to const_iterator
            typedef ft::random_access_iterator<value_type> iterator;
        // const_iterator	a random access iterator to const value_type	
            typedef ft::random_access_const_iterator<value_type> const_iterator;
        // reverse_iterator	reverse_iterator<iterator>	
            typedef ft::reverse_iterator<iterator> reverse_iterator;
        // const_reverse_iterator	reverse_iterator<const_iterator>	
            typedef ft::const_reverse_iterator<iterator> cont_reverse_iterator;
        // difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
            typedef ft::iterator_traits<iterator>::difference_type difference_type
        // size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
            typedef size_t size_type;
        // Member functions
        // constructor
        // (1) empty container constructor (default constructor)
        // Constructs an empty container, with no elements.
            explicit vector(const allocator_type& alloc = allocator_type()) {
                _allocator = allocator;
                _vector = _allocator.allocate(0);
                _size = 0;
            };
        // (2) fill constructor
        // Constructs a container with n elements. Each element is a copy of val.
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
                _allocator = allocator;
                _vector = allocator.allocate(0);
                _vector = _vector.assign(n,val);
                _size = n;
            };
        // (3) range constructor
        // Constructs a container with as many elements as the range [first,last), 
        // with each element constructed from its corresponding element in that range, in the same order.
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
                _allocator = allocator;
                _vector = allocator.allocate(0);
                _vector = _vector.assign(first,last);
                size = last - first;
            };	
        // (4) copy constructor
        // Constructs a container with a copy of each of the elements in x, in the same order.
            vector (const vector& x) {
                *this = x;
            };
        // destructor
            ~vector() {
                _allocator.deallocate(_vector, _size)
            };
        // Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
            vector& operator= (const vector& x) {
                _allocator.deallocate(_vector, _size);
                _alllocator = x._allocator;
                _vector = _vector.assign(x.begin(), x.end());
                _size = x._size;
                return(*this);
            };
        //iterators
        // Returns an iterator pointing to the first element in the vector.
        // this function returns a random access iterator pointing to it.
            iterator begin() {
                return(iterator(_vector));
            };
            const_iterator begin() const {
                return(const_iterator(_vector));
            };
        // Returns an iterator referring to the past-the-end element in the vector container.
            iterator end() {
                return(iterator(_vector + _size));
            };
            const_iterator end() const {
                return(const_iterator(_vector + _size));
            };
    }

}

// Member functions
// (constructor)	Construct vector (public member function)
// (destructor)	Vector destructor (public member function)
// operator=	Assign content (public member function)

// Iterators:
// begin	Return iterator to beginning (public member function)
// end	Return iterator to end (public member function)
// rbegin	Return reverse iterator to reverse beginning (public member function)
// rend	Return reverse iterator to reverse end (public member function)
// cbegin	Return const_iterator to beginning (public member function)
// cend	Return const_iterator to end (public member function)
// crbegin	Return const_reverse_iterator to reverse beginning (public member function)
// crend	Return const_reverse_iterator to reverse end (public member function)

// Capacity:
// size	Return size (public member function)
// max_size	Return maximum size (public member function)
// resize	Change size (public member function)
// capacity	Return size of allocated storage capacity (public member function)
// empty	Test whether vector is empty (public member function)
// reserve	Request a change in capacity (public member function)
// shrink_to_fit	Shrink to fit (public member function)

// Element access:
// operator[]	Access element (public member function)
// at	Access element (public member function)
// front	Access first element (public member function)
// back	Access last element (public member function)
// data	Access data (public member function)

// Modifiers:
// assign	Assign vector content (public member function)
// push_back	Add element at the end (public member function)
// pop_back	Delete last element (public member function)
// insert	Insert elements (public member function)
// erase	Erase elements (public member function)
// swap	Swap content (public member function)
// clear	Clear content (public member function)
// emplace	Construct and insert element (public member function)
// emplace_back	Construct and insert element at the end (public member function)

// Allocator:
// get_allocator	Get allocator (public member function)

// Non-member function overloads
// relational operators	Relational operators for vector (function template)
// swap	Exchange contents of vectors (function template)

// Template specializations
// vector<bool>	Vector of bool (class template specialization)

#endif