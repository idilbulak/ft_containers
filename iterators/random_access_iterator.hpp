#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
    template <class T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		private:
			T*		_vecptr;
		public:
			random_access_iterator(void) : _vecptr(nullptr) {}
			random_access_iterator(T* ptr) : _vecptr(ptr) {}
			random_access_iterator(const random_access_iterator& other) {*this = other;}
			random_access_iterator&	operator=(const random_access_iterator& other) {_vecptr = other._vecptr; return (*this);}
			virtual ~random_access_iterator(void) {}
			bool operator==(const random_access_iterator &other) const {return (_vecptr == other._vecptr);}
			bool operator!=(const random_access_iterator &other) const {return (_vecptr != other._vecptr);}
			T& operator*(void) {return (*_vecptr);}
			T* operator->(void) {return (_vecptr);}
			random_access_iterator&	operator++(void) {++_vecptr; return (*this);}
			random_access_iterator operator++(int) {random_access_iterator	tmp(*this); operator++(); return (tmp);}
			random_access_iterator&	operator--(void) {--_vecptr; return (*this);}
			random_access_iterator operator--(int) {random_access_iterator	tmp(*this); operator--(); return (tmp);}
			random_access_iterator operator+(int n) {return (random_access_iterator(_vecptr + n));}
			random_access_iterator operator-(int n) {return (random_access_iterator(_vecptr - n));}
			bool operator<(const random_access_iterator &other) const {return (_vecptr < other._vecptr);}
			bool operator>(const random_access_iterator &other) const {return (_vecptr > other._vecptr);}
			bool operator<=(const random_access_iterator &other) const {return (!(_vecptr > other._vecptr));}
			bool operator>=(const random_access_iterator &other) const {return (!(_vecptr < other._vecptr));}
			random_access_iterator &operator+=(int n) {_vecptr += n; return (*this);}
			random_access_iterator &operator-=(int n) {_vecptr -= n; return (*this);}
			T& operator[](int n) {return (*(_vecptr + n));}
	};
}

#endif

// https://cplusplus.com/reference/iterator/RandomAccessIterator/