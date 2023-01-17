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
	std::cout << "\033[1;31m=============constructors=============\033[0m" << std::endl;

	std::cout << "\033[32mcreating empty vector of ints..\033[0m" << std::endl;
	ft::vector<int> first;
	std::cout << "[first]" << std::endl;
	std::cout << "if_empty: " << std::boolalpha << first.empty() << std::endl;
	std::cout << "size: " << first.size() << std::endl;

	std::cout << "\033[32mcreating four ints with value 100..\033[0m" << std::endl;
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
	
	return (0);
}