#include "../containers/vector.hpp"
#include <iostream>

template <class T>
void iterate_print(ft::vector<T> &vector)
{
	typedef typename ft::vector<T>::iterator iter;
	typedef typename ft::vector<T>::reverse_iterator reverse_iter;
	
	std::cout << "with iterator:";
	for (iter it = vector.begin(); it != vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	
	std::cout << "with reverse_iterator:";
	for (reverse_iter it = vector.rbegin(); it != vector.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

int main (void)
{
	std::cout << "\033[1;31m_____________constructor_____________\033[0m" << std::endl;

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
	iterate_print(second);

	std::cout << "\033[32miterating through second..\033[0m" << std::endl;
	ft::vector<int> third (second.begin(),second.end());
	std::cout << "[third]" << std::endl;
	std::cout << "if_empty: " << std::boolalpha << third.empty() << std::endl;
	std::cout << "size: " << third.size() << std::endl;
	iterate_print(third);

	std::cout << "\033[32mcreating a copy of third..\033[0m" << std::endl;
	ft::vector<int> fourth (third);
	std::cout << "[fourth]" << std::endl;
	std::cout << "if_empty: " << std::boolalpha << fourth.empty() << std::endl;
	std::cout << "size: " << fourth.size() << std::endl;
	iterate_print(fourth);

	std::cout << "\033[32mconstructing from array myints[] = {16,2,77,29}..\033[0m" << std::endl;
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "[fifth]" << std::endl;
	std::cout << "if_empty: " << std::boolalpha << fifth.empty() << std::endl;
	std::cout << "size: " << fifth.size() << std::endl;
	iterate_print(fifth);

	std::cout << "\033[1;31m_____________operator=_____________\033[0m" << std::endl;
	ft::vector<int> foo ((unsigned int)3,0);
	ft::vector<int> bar;
	bar = foo;
	foo = ft::vector<int>();
	std::cout << "Size of foo: " << int(foo.size()) << "(should be 0)" << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << "(should be 3)" << '\n';
	
	std::cout << "\033[1;31m_____________capacity_____________\033[0m" << std::endl;
	ft::vector<int> myvector;
	for (int i=1; i<=10; i++) myvector.push_back(i);
	iterate_print(myvector);
	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "if_empty: " << std::boolalpha << myvector.empty() << std::endl;
	myvector.resize(5);
	std::cout << "after resize(5), size: " << myvector.size() << std::endl;
	iterate_print(myvector);
	myvector.resize(8, 100);
	std::cout << "after resize(8, 100), size: " << myvector.size() << std::endl;
	iterate_print(myvector);
	myvector.resize(12);
	std::cout << "after resize(12), size: " << myvector.size() << std::endl;
	iterate_print(myvector);


	return (0);
}