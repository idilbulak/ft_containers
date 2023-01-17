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

	// std::cout << "======resize & size & capcity ==========" << std::endl;

	// ft::vector<int> myvector;
	// for (int i=1;i<10;i++)
	// 	myvector.push_back(i);
	// std::cout << "size: " << (int) myvector.size() << '\n';
	// std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	// std::cout << "max_size: " << myvector.max_size() << '\n';
	
	// iterate_print(myvector);
	// myvector.resize(5);
	// iterate_print(myvector);
	// myvector.resize(8,100);
	// iterate_print(myvector);
	// myvector.resize(12);
	// iterate_print(myvector);

	// std::cout << "myvector contains:";
	// for (unsigned int i=0;i<myvector.size();i++)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// std::cout << "======reserve==========" << std::endl;
	// ft::vector<int>::size_type sz;

	// ft::vector<int> x;
	// sz = x.capacity();
	// std::cout << "making x grow:\n";
	// for (int i=0; i<100; ++i) 
	// {
	// 	x.push_back(i);
	// 	if (sz != x.capacity()) 
	// 	{
	// 		sz = x.capacity();
	// 		std::cout << "capacity changed: " << sz << '\n';
	// 	}
	// }

	// ft::vector<int> y;
	// sz = y.capacity();
	// y.reserve(100);   // this is the only difference with x above
	// std::cout << "making y grow:\n";
	// for (int i=0; i<100; ++i) {
	// 	y.push_back(i);
	// 	if (sz != y.capacity()) 
	// 	{
	// 		sz = y.capacity();
	// 		std::cout << "capacity changed: " << sz << '\n';
	// 	}
    // }
	// std::cout << "=======operator []=========" << std::endl;

	// ft::vector<int> vec(10);
	// ft::vector<int>::size_type sz2 = vec.size();
	// for (unsigned i=0; i < sz2; i++) 
	// 	vec[i] = i;
	// for (unsigned i=0; i < sz2 / 2; i++)
	// {
	// 	int temp;
	// 	temp = vec[sz2-1-i];
	// 	vec[sz2-1-i] = vec[i];
	// 	vec[i]=temp;
	// }

	// std::cout << "myvector contains:";
	// for (unsigned i = 0; i < sz2; i++)
	// 	std::cout << ' ' << vec[i];
	// std::cout << '\n';

	// std::cout << "=======at=========" << std::endl;
	// for (unsigned i = 0 ; i< vec.size(); i++)
    // 	vec.at(i) = i;
	// std::cout << "myvector contains:";
	// for (unsigned i = 0; i < sz2; i++)
	// 	std::cout << ' ' << vec.at(i);
	// std::cout << '\n';
	// try
	// {
	// 	vec.at(-1);
	// }
	// catch (std::exception const &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << "=======front & back & push_back & pop_back=========" << std::endl;
	// iterate_print(vec);
	// std::cout << "front : " << vec.front() << std::endl;
	// std::cout << "back : " << vec.back() << std::endl;
	// vec.push_back(123);
	// iterate_print(vec);
	// std::cout << "burdaaaaaaaaaaaaaaaaa" << std::endl;
	// vec.pop_back();
	// iterate_print(vec);


	
	// std::cout << "=======front & back & push_back & pop_back=========" << std::endl;
	
	// ft::vector<int> vec1;
	// ft::vector<int> vec2;
	// ft::vector<int> vec3;

	// vec1.assign ((unsigned int)7,100);             // 7 ints with a value of 100
	// iterate_print(vec1);
	// ft::vector<int>::iterator it;
	// it = vec1.begin() + 1;

	// vec2.assign (it, vec1.end() - 1); // the 5 central values of first
	// iterate_print(vec2);

	// int myints2[] = {1776,7,4};
	// vec3.assign (myints2 , myints2 + 3);   // assigning from array.
	// iterate_print(vec3);

	// std::cout << "Size of first: " << int (vec1.size()) << '\n';
	// std::cout << "Size of second: " << int (vec2.size()) << '\n';
	// std::cout << "Size of third: " << int (vec3.size()) << '\n';

	// std::cout << "========erase=========" << std::endl;
	// iterate_print(vec);
	// vec.erase(vec.begin() + 5);
	// iterate_print(vec);
	// vec.erase(vec.begin(), vec.begin() + 3);
	// iterate_print(vec);

	// std::cout << "========swap=========" << std::endl;
	
	// ft::vector<int> a((unsigned int)3, 100);
	// std::cout << "a: ";
	// iterate_print(a);
	// ft::vector<int> b((unsigned int)5, 200);
	// a.swap(b);
	// std::cout << "a: ";
	// iterate_print(a);

	// std::cout << "========swap=========" << std::endl;

	// ft::vector<int> foo ((unsigned int)3,100);   // three ints with a value of 100
	// ft::vector<int> bar ((unsigned int)2,200);   // two ints with a value of 200

	// if (foo==bar) std::cout << "foo and bar are equal\n";
	// if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// if (foo< bar) std::cout << "foo is less than bar\n";
	// if (foo> bar) std::cout << "foo is greater than bar\n";
	// if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	
	return (0);
}