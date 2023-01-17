#ifndef REVERSE_iTERATOR_HPP
# define REVERSE_iTERATOR_HPP

namespace ft {
	template <class iterator>
	class   reverse_iterator
	{
		private:
			iterator	_base;
		public:
			typedef iterator	iterator_type;
			typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator>::value_type			value_type;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;
			typedef typename iterator_traits<iterator>::pointer				pointer;
			typedef typename iterator_traits<iterator>::reference			reference;
			reverse_iterator(void) {}
			explicit reverse_iterator(iterator_type it) : _base(it) {}
			reverse_iterator(const reverse_iterator<iterator>& other) {*this = other;}
			~reverse_iterator(void) {};
			iterator_type	base(void) const {return (_base);}
			reference		operator*(void) const {iterator_type tmp(_base); return (*--tmp);}
			reverse_iterator	operator+(difference_type n) const {return (reverse_iterator(_base - n));}
			reverse_iterator&	operator++() {--_base; return (*this);}
			reverse_iterator	operator++(int) {reverse_iterator<iterator> tmp = *this; ++(*this); return (tmp);}
			reverse_iterator& operator+=(difference_type n) {_base -= n; return (*this);}
			reverse_iterator	operator-(difference_type n) const {return (reverse_iterator(_base + n));}
			reverse_iterator&	operator--() {++_base; return (*this);}
			reverse_iterator	operator--(int) {reverse_iterator<iterator> tmp = *this; --(*this); return (tmp);}
			reverse_iterator& operator-=(difference_type n) {_base += n; return (*this);}
			pointer operator->() const {return &(operator*());}
			reference operator[] (difference_type n) const {return (base()[-n-1]);}
	};
	template <class iterator>
	bool operator==(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {return (lhs.base() == rhs.base());}
	template <class iterator>
	bool operator!=(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {return (lhs.base() != rhs.base());}
	template <class iterator>
	bool operator<(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {return (lhs.base() < rhs.base());}
	template <class iterator>
	bool operator<=(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {return (lhs.base() <= rhs.base());}
	template <class iterator>
	bool operator>(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {return (lhs.base() > rhs.base());}
	template <class iterator>
	bool operator>=(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {return (lhs.base() >= rhs.base());}
	template <class iterator>
	reverse_iterator<iterator> operator+(typename reverse_iterator<iterator>::difference_type n, const reverse_iterator<iterator>& rev_it) {return (rev_it + n);}
	template <class iterator>
	typename reverse_iterator<iterator>::difference_type operator-(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {return (rhs.base() - lhs.base());}
}

#endif

// https://cplusplus.com/reference/iterator/reverse_iterator/