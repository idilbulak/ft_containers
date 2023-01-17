#include "../containers/vector.hpp"
#include <iostream>

template <class T>
void test_iterate(ft::vector<T> &vector)
{
	typedef typename ft::vector<T>::iterator iter;
	typedef typename ft::vector<T>::reverse_iterator reverse_iter;
	
	std::cout << "vector=";
	for (iter it = vector.begin(); it != vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template <class T>
void test_reverseiterate(ft::vector<T> &vector)
{
	typedef typename ft::vector<T>::reverse_iterator reverse_iter;
	std::cout << "reverse_vector=";
	for (reverse_iter it = vector.rbegin(); it != vector.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_constructor ()
{
	std::cout << "\033[32mcreating empty vector of ints..\033[0m" << std::endl;
	ft::vector<int> first;
	std::cout << "[first]" << std::endl;
	std::cout << "if_empty: " << std::boolalpha << first.empty() << std::endl;
	std::cout << "size: " << first.size() << std::endl;

	std::cout << "\033[32mcreating vector with four ints with value 100..\033[0m" << std::endl;
	ft::vector<int> second ((unsigned int)4,100);
	std::cout << "[second]" << std::endl;
	std::cout << "if_empty: " << std::boolalpha << second.empty() << std::endl;
	std::cout << "size: " << second.size() << std::endl;
	test_iterate(second);

	std::cout << "\033[32miterating through second..\033[0m" << std::endl;
	ft::vector<int> third (second.begin(),second.end());
	std::cout << "[third]" << std::endl;
	std::cout << "if_empty: " << std::boolalpha << third.empty() << std::endl;
	std::cout << "size: " << third.size() << std::endl;
	test_iterate(third);

	std::cout << "\033[32mcreating a copy of third..\033[0m" << std::endl;
	ft::vector<int> fourth (third);
	std::cout << "[fourth]" << std::endl;
	std::cout << "if_empty: " << std::boolalpha << fourth.empty() << std::endl;
	std::cout << "size: " << fourth.size() << std::endl;
	test_iterate(fourth);

	std::cout << "\033[32mconstructing from array myints[] = {16,2,77,29}..\033[0m" << std::endl;
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "[fifth]" << std::endl;
	std::cout << "if_empty: " << std::boolalpha << fifth.empty() << std::endl;
	std::cout << "size: " << fifth.size() << std::endl;
	test_iterate(fifth);
}

void test_operator_equal ()
{
	std::cout << "\033[1;31m_____________operator=_____________\033[0m" << std::endl;
	ft::vector<int> foo ((unsigned int)3,0);
	ft::vector<int> bar;
	bar = foo;
	foo = ft::vector<int>();
	std::cout << "Size of foo: " << int(foo.size()) << "(should be 0)" << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << "(should be 3)" << '\n';
}

void test_size ()
{
	ft::vector<int> myvector;
	for (int i=1; i<10; i++) myvector.push_back(i);
	test_iterate(myvector);
	std::cout << "size: " << myvector.size() << std::endl;
}

void test_maxsize ()
{
	ft::vector<int> myvector;
	for (int i=1; i<10; i++) myvector.push_back(i);
	test_iterate(myvector);
	std::cout << "max_size: " << myvector.max_size() << std::endl;
}

void test_capacity ()
{
	ft::vector<int> myvector;
	for (int i=1; i<10; i++) myvector.push_back(i);
	test_iterate(myvector);
	std::cout << "capacity: " << myvector.capacity() << std::endl;
}

void test_empty ()
{
	ft::vector<int> myvector;
	for (int i=1; i<10; i++) myvector.push_back(i);
	test_iterate(myvector);
	std::cout << "if_empty: " << std::boolalpha << myvector.empty() << std::endl;
}

void test_resize ()
{
	ft::vector<int> myvector;
	for (int i=1; i<10; i++) myvector.push_back(i);
	test_iterate(myvector);
	myvector.resize(5);
	std::cout << "after resize(5), size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	test_iterate(myvector);
	myvector.resize(8, 100);
	std::cout << "after resize(8, 100), size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	test_iterate(myvector);
	myvector.resize(12);
	std::cout << "after resize(12), size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	test_iterate(myvector);
}

void test_reserve()
{
  ft::vector<int>::size_type sz;
  ft::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';}}
  ft::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';}}
}

// void test_shrink_to_fit()
// {
//   ft::vector<int> myvector (100);
//   std::cout << "1. capacity of myvector: " << myvector.capacity() << '\n';

//   myvector.resize(10);
//   std::cout << "2. capacity of myvector: " << myvector.capacity() << '\n';
// 	test_iterate(myvector);
//   myvector.shrink_to_fit();
//   std::cout << "3. capacity of myvector: " << myvector.capacity() << '\n';
// 	test_iterate(myvector);
// }

void test_operator_square()
{
  ft::vector<int> myvector (10);   // 10 zero-initialized elements
  ft::vector<int>::size_type sz = myvector.size();
  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;
  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }
  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

void test_at()
{
  ft::vector<int> myvector (10);   // 10 zero-initialized ints
  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;
  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
}

void test_front()
{
  ft::vector<int> myvector;
  myvector.push_back(78);
  myvector.push_back(16);
  // now front equals 78, and back 16
  myvector.front() -= myvector.back();
  std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void test_back()
{
  ft::vector<int> myvector;
  myvector.push_back(10);
  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }
  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

// void test_data()
// {
//   ft::vector<int> myvector (5);
//   int* p = myvector.data();
//   *p = 10;
//   ++p;
//   *p = 20;
//   p[2] = 100;
//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
// }


int main (void)
{
  ft::vector<int> first;
  ft::vector<int> second;
  ft::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

//   ft::vector<int>::iterator it;
//   it=first.begin()+1;

//   second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
	return (0);
}