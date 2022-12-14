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
                _allocator = alloc;
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
        // Returns a reverse iterator pointing to the last element in the vector 
            reverse_iterator rbegin() {
                return(reverse_iterator(_vector + _size - 1));
            };
            const_reverse_iterator rbegin() const {
                return(const_reverse_iterator(_vector + _size - 1));
            };
        // Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end). 
            reverse_iterator rend() {
                return(reverse_iterator(_vector - 1));
            };
            const_reverse_iterator rend() const {
                return(const_reverse_iterator(_vector - 1));
            };
        // Returns a const_iterator pointing to the first element in the container. 
            const_iterator cbegin() const noexcept {
                return(iterator(_vector));
            };
        // Returns a const_iterator pointing to the past-the-end element in the container.
            const_iterator cend() const noexcept {
                return(iterator(_vector + _size));
            };
        // Returns a const_reverse_iterator pointing to the last element in the container
            const_reverse_iterator crbegin() const noexcept {
                return(const_reverse_iterator(_vector + _size - 1));
            };
        // Returns a const_reverse_iterator pointing to the theoretical element preceding the first element in the container
            const_reverse_iterator crend() const noexcept {
                return(const_reverse_iterator(_vector - 1));
            };
        //capacity
        //Returns the number of elements in the vector.
            size_type size() const {
                return (_size);
            };
        // Returns the maximum number of elements that the vector can hold.
            size_type max_size() const {
                return(allocator_type().max_size());
            };
        // Resizes the container so that it contains n elements.
            void resize (size_type n, value_type val = value_type()) {
                while (n < _size)
                   _vector = _vector.pop_back();
                while (n < _size)
                   _vector = _vector.push_back(val);
            };
        // Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
            size_type capacity() const {
                return(_size);
            };
        // Returns whether the vector is empty
            bool empty() const {
                if (_size == 0)
                    return(true);
                return(false); 
            };
        //Requests that the vector capacity be at least enough to contain n elements.
            void reserve (size_type n) {
                if (_vector.capacity() >= n)
                    return;
                size_type temp_cap = _capacity;
                _capacity = n;
                T tmp = _vector;
                &_vector = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; ++i)
                    _vector + i = tmp + i;
                for(T it = tmp; it != tmp + _size; ++it)
                        _alloc.destroy(it);
                if (temp_cap > 0)
                    _alloc.deallocate(tmp, temp_cap);
            };
        // Requests the container to reduce its capacity to fit its size.
            void shrink_to_fit() {
                
            };
        //element access
        // Returns a reference to the element at position n in the vector container.
            reference operator[] (size_type n) {
                if (n > _size)
                    throw std::out_of_range();
                return (*(_vector + n));
            };
            const_reference operator[] (size_type n) const {
                if (n > _size)
                    throw std::out_of_range();
                return (*(_vector + n));
            };
        // Returns a reference to the element at position n in the vector.
            reference at (size_type n) {
                if (n >= _size || n < 0)
                    throw std::out_of_range();
                return (*(_vector + n));
            };
            const_reference at (size_type n) const {
                if (n >= _size || n < 0)
                    throw std::out_of_range();
                return (*(_vector + n));
            };
        // Returns a reference to the first element in the vector.
            reference front() {
                if (empty())
                    throw std::out_of_range();
                return (*(_vector));
            };
            const_reference front() const {
                if (empty())
                    throw std::out_of_range();
                return (*(_vector));
            };
        // Returns a reference to the last element in the vector.
            reference back() {
                if (empty())
                    throw std::out_of_range();
                return *(_vector + _size - 1);
            };
            const_reference back() const {
                if (empty())
                    throw std::out_of_range();
                return *(_vector + _size - 1);
            };

    };
}

#endif