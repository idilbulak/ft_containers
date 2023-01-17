#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include <iostream>

namespace ft {
    template <class T, class Alloc = std::allocator<T> >
    class vector {
        public:
            // member types
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference; 
            typedef typename allocator_type::const_reference const_reference; 
            typedef typename allocator_type::pointer pointer; 
            typedef typename allocator_type::const_pointer const_pointer; 
            typedef ft::random_access_iterator<T> iterator;
            typedef ft::random_access_iterator<const T> const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
        private:
            pointer _vecptr;
            allocator_type _alloc;
            size_type _size;
            size_type _capacity;
        public:
            // constructor
            explicit vector(const allocator_type& alloc = allocator_type()): _vecptr(nullptr), _size(0), _capacity(0), _alloc(alloc) {}	
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _vecptr(nullptr), _size(n), _capacity(n), _alloc(alloc) {
				_vecptr = _alloc.allocate(n);
				for (unsigned int i = 0; i < n; ++ i)
					_alloc.construct(&_vecptr[i], val);}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _vecptr(nullptr), _size(0), _capacity(0), _alloc(alloc){
				_vecptr = _alloc.allocate(0);
				assign(first, last);}
			vector(const vector& other): _vecptr(nullptr), _size(0), _capacity(0) {*this = other;}
            // destructor
			~vector() {_alloc.deallocate(_vecptr, _capacity + 1);}
            // copy assignment
			vector&	operator=(const vector<T>& vec) {
				_alloc.deallocate(_vecptr, _capacity + 1);
				assign(vec.begin(), vec.end());
				return (*this);}
            // iterators
			iterator begin(void) {return (iterator(_vecptr));}
			const_iterator begin(void) const {return (const_iterator(_vecptr));}
			iterator end(void) {return (iterator(_vecptr + _size));}
			const_iterator end(void) const {return (const_iterator(_vecptr + _size));}
			reverse_iterator rbegin(void) {return (reverse_iterator(end()));}
			const_reverse_iterator rbegin() const {return (const_reverse_iterator(end()));}
			reverse_iterator rend(void) {return (reverse_iterator(begin()));}
			const_reverse_iterator rend() const {return (const_reverse_iterator(begin()));}
            // capacity
            size_type	size(void) const {return (_size);}
			size_type	max_size(void) const {return(allocator_type().max_size());}
			void resize(size_type n, value_type val = value_type()) {
				while (n < _size)
					pop_back();
				while (n > _size)
					push_back(val);}
			size_type capacity() const {return (_capacity);}
			bool	empty(void) const {return (_size == 0);}
			void reserve(size_type n) {
				if (n > max_size())
					throw std::length_error("error: reserve");
				T* tmp = _alloc.allocate(n);
				for (unsigned int i = 0; i < _size; ++ i)
					_alloc.construct(&tmp[i], _vecptr[i]);
				_alloc.deallocate(_vecptr, _capacity + 1);
				_vecptr = tmp;
				_capacity = n;}
            void shrink_to_fit() {
				if (_vecptr.capacity() > _size) {
					// _allocdestroy(_vecptr + (_size));
					_alloc.deallocate(_vecptr + (_size), _vecptr.capacity() - _size);
					_capacity = _size;}}
            // element access
			reference operator[](size_type n) {return (_vecptr[n]);}
			const_reference operator[](size_type n) const {return (_vecptr[n]);}
			reference at(size_type n) {
				if (n >= _size)
					throw std::out_of_range("error: at");
				return (_vecptr[n]);}
			const_reference at(size_type n) const {
				if (n >= _size)
					throw std::out_of_range("error: at");
				return (_vecptr[n]);}
			reference front() {return (*_vecptr);}
			const_reference front() const {return (*_vecptr);}
			reference	back(void) {return (*(_vecptr + _size - 1));}
			const_reference	back(void) const {return (*(_vecptr + _size - 1));}
            // data	Access data (public member function)
            // modifiers
			template <class InputIterator>
 			void	assign(InputIterator first, InputIterator last) {
				if (_size)
					clear();
				size_type n = 0;
				for (InputIterator it = first; it != last; ++it)
					++n;
				if (n > _capacity) {
					reserve(n);
                    _capacity = n;}
				for (InputIterator it = first; it != last; ++it) {
					_alloc.construct(&_vecptr[_size], *it);
					++_size;}}
			void	assign(size_type n, const value_type& val) {
				if (_size)
					clear();
				if (n > _capacity) {
					reserve(n);
                    _capacity = n;}
				while (_size < n) {
					_alloc.construct(&_vecptr[_size], val);
					++_size;}}
			void push_back(const value_type& val) {
				if	(_capacity == 0)
					reserve(1);
				if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				_alloc.construct(&_vecptr[_size], val);
				++_size;}
			void pop_back() {
				--_size;
				_alloc.destroy(_vecptr +_size);}
			iterator insert(iterator position, const value_type& val) {
				insert(position, (size_t)1, val);
				return (position);}
			void insert(iterator position, size_type n, const value_type& val) {
				while (1) {				
					if	(_capacity == 0)
						reserve(1);
					else if (_size + n > _capacity)
						reserve(_capacity * 2);
					else
						break;}
				int i = 0;
				for (iterator it = position; it != end(); ++it)
				{
					_alloc.construct(&_vecptr[_size + n - i], _vecptr[_size - i]);
					++i;
				}
				for (; i < 0; --i)
					_vecptr[_size - i] = val;
				_size += n;
				_size++;}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last) {
				int	n = 0;
				for (iterator it = first; it != last; ++it)
					++n;
				while (1) {				
					if	(_capacity == 0)
						reserve(1);
					else if (_size + n > _capacity)
						reserve(_capacity * 2);
					else
						break;}
				int i = 0;
				for (iterator it = position; it != end(); ++it) {
					_alloc.construct(&_vecptr[_size + n - i], _vecptr[_size - i]);
					++i;}
				for (iterator it = first; it != last; ++it) {
					_vecptr[_size - i] = *it;
					--i;}
				_size += n;}
			iterator erase(iterator position) {
				size_t	pos = 0;
				iterator it = begin();
				while(it++ != position)
					++pos;
				--_size;
				iterator	ret = it;
				while (pos < _size)
					_vecptr[pos++] = *it++;
				_alloc.destroy(&(_vecptr[pos]));
				return (ret); }
			iterator erase(iterator first, iterator last) {
				size_type	old_size = _size;
				size_type	pos = 0;
				iterator it;
				for (it = begin(); it != first; ++it)
					++pos;
				while (it != last) {
					--_size;
					++it;}
				iterator	ret = it;
				while (pos < _size)
					_vecptr[pos++] = *it++;
				while (pos < old_size)
					_alloc.destroy(&(_vecptr[pos++]));
				return (ret);}
			void swap (vector& x) {
				std::swap(_vecptr, x._vecptr);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_alloc, x._alloc);}
			void clear() {
				while (_size) {
					--_size;
					_alloc.destroy(&(_vecptr[_size - 1]));}}
// emplace	Construct and insert element (public member function)
// emplace_back	Construct and insert element at the end (public member function)
// get_allocator	Get allocator (public member function)
	};
    // relational operators
	template <class T, class Alloc>
	bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			if (lhs[i] != rhs[i])
				return (false);}
		return (true);}
	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return (!(lhs == rhs));}
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		unsigned int	n;
		if (lhs.size() < rhs.size())
			n = lhs.size();
		else
			n = rhs.size();
		for (unsigned int i = 0; i < n; ++i) {
			if (lhs[i] < rhs[i])
				return (true);
			else if (lhs[i] > rhs[i])
				return (false);}
		return (lhs.size() < rhs.size());}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return (!(rhs < lhs));}
	template <class T, class Alloc>
 	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return (rhs < lhs);}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return (!(lhs < rhs));}
	template <class T, class Alloc>
    // swap
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {x.swap(y);}    
}

#endif