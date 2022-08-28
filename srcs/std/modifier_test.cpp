#include "vector_test.hpp"

void	modifier_test(void)
{

	std::cout << "--PUSH_BACK-&&-POP_BACK--" << std::endl;
	std::vector<int> first;
	print(first, "first");

	first.push_back(9);
	print(first, "first");

	first.push_back(7);
	print(first, "first");

	first.push_back(5);
	print(first, "first");

	first.push_back(3);
	print(first, "first");

	first.push_back(4);
	print(first, "first");

	first.pop_back();
	print(first, "first");

	first.pop_back();
	print(first, "first");

	first.pop_back();
	print(first, "first");

	first.pop_back();
	print(first, "first");

	first.pop_back();
	print(first, "first");

	first.push_back(6);
	print(first, "first");

	first.push_back(66);
	print(first, "first");

	first.push_back(666);
	print(first, "first");

	first.push_back(6666);
	print(first, "first");


	std::cout << "--ASSIGN--" << std::endl;
	std::vector<int> second;
	std::vector<int> third;

	first.assign(7, 100);
	second.assign(first.begin(), first.end());

	std::cout <<"-----1-----"<< std::endl;
	print(first, "first");
	print(second, "second");

	std::cout <<"-----2-----"<< std::endl;
	second[1] = 9;
	print(second, "second");
	first.assign(second.begin(), second.begin() + 2);
	print(first, "first");

	std::cout <<"-----3-----"<< std::endl;
	first.assign(4, 10);
	print(first, "first");



	std::cout <<"-----4-----"<< std::endl;
	int	myints[] = {1, 2, 3, 4, 5};
	std::cout << "Size of third : " << third.size() << std::endl;
	third.assign (myints, myints + 5);
	std::cout << "Size of third : " << third.size() << ' ' << third.capacity() << std::endl << std::endl;
	print(second, "second");
	print(third, "third");

	std::cout <<"-----5-----"<< std::endl;
	std::vector<std::string>		fourth;
	std::vector<std::string>		fifth;
	fourth.assign(3, "Hello !");
	print(fourth, "fourth");

	std::cout <<"-----6-----"<< std::endl;
	std::vector<std::string>::const_iterator scit = fourth.begin();
	std::vector<std::string>::const_iterator scite = fourth.end();
	std::vector<std::string>::iterator sit = fourth.begin();
	fifth.assign(scit, scite);
	print(fifth, "fifth");

	std::cout <<"-----7-----"<< std::endl;
	sit = fifth.begin();
	*sit = "HIHI";
	print(fifth, "fifth");


	std::cout <<"-----8-----"<< std::endl;
	first.assign (7, 100);
	print(first, "first");
	
	std::cout <<"-----9-----"<< std::endl;
	second.assign (first.begin() + 1, first.end() - 2);
	print(second, "second");
	
	std::cout <<"-----10----"<< std::endl;
	third.assign (myints, myints + 5);
	print(third, "third");

	std::cout <<"-----11----"<< std::endl;
	first.assign(third.begin(), third.end() - 3);
	print(first, "first");

	std::cout <<"-----12----"<< std::endl;
	third.assign(first.begin(), first.end());
	print(third, "third");


	std::cout << "--INSERT--" << std::endl;
	std::vector<int>::iterator	it = first.begin();
	it = first.begin();

	std::cout << "-----1-----" << std::endl;
	it = first.insert(first.end(), 100);
	std::cout << "IT " << *it << std::endl;
	print(first, "first");

	std::cout << "MIT " << *it << std::endl;

	std::cout << "-----2-----" << std::endl;
	it = first.insert(first.begin(), 200);
	std::cout << "IT " << *it << std::endl;
	print(first, "first");

	std::cout << "MIT " << *it << std::endl;

	std::cout << "-----3-----" << std::endl;
	it = first.insert(first.begin() + 2, 300);
	std::cout << "IT " << *it << std::endl;
	print(first, "first");

	std::cout << "MIT " << *it << std::endl;

	std::cout << "-----4-----" << std::endl;
	it = first.insert(first.begin() + 2, 400);
	std::cout << "IT " << *it << std::endl;
	print(first, "first");

	std::cout << "MIT " << *it << std::endl;

	std::cout << "-----5-----" << std::endl;
	first.insert(first.begin(), 3, 600);
	print(first, "first");


	std::cout << "-----6-----" << std::endl;
	first.insert(first.begin() + 3, 3 , 700);
	print(first, "first");


	std::cout << "-----7-----" << std::endl;
	first.insert(first.end(), 3 , 800);
	print(first, "first");

	int i = 0;

	std::cout << "-----8-----" << std::endl;
	for (; i < 3; ++i)
		second.push_back(i);
	first.insert(first.begin(), second.begin(), second.end());
	print(first, "first");

	std::cout << "-----9-----" << std::endl;
	second.clear();
	for (; i < 6; ++i)
		second.push_back(i);
	first.insert(first.begin() + 3, second.begin(), second.end());
	print(first, "first");

	std::cout << "-----10----" << std::endl;
	second.clear();
	for(; i < 9;++i)
		second.push_back(i);
	first.insert(first.end(), second.begin(), second.end());
	print(first, "first");

	int	array [] = {501, 502, 503};

	std::cout << "-----11----" << std::endl;
	first.insert(first.begin(), array, array + 3);
	print(first, "first");

	try
	{
	std::cout << "-----12----" << std::endl;
		first.insert(first.end(), array + 3, array + 2);
		print(first, "first");
	}
	catch(std::exception &e){std::cout << e.what() << std::endl;}


	std::cout << "--ERASE--" << std::endl;
	std::vector<int>::iterator test;

	print(first, "first");

	std::cout << "1" << std::endl;
	test = first.erase(first.begin());
	std::cout << "TEST " << *test << std::endl;
	print(first, "first");

	std::cout << "2" << std::endl;
	test = first.erase(first.end() - 1);
	std::cout << "TEST " << *test << std::endl;
	print(first, "first");

	std::cout << "3" << std::endl;
	test = first.erase(first.begin() + 3);
	std::cout << "TEST " << *test << std::endl;
	print(first, "first");

	std::cout << "4" << std::endl;
	test = first.erase(first.begin() + 7, first.end());
	std::cout << "TEST " << *test << std::endl;
	print(first, "first");

	std::cout << "5" << std::endl;
	test = first.erase(first.begin(), first.begin() + 3);
	std::cout << "TEST " << *test << std::endl;
	print(first, "first");

	std::cout << "6" << std::endl;
	test = first.erase(first.begin() + 1, first.begin() + 1);
	std::cout << "TEST " << *test << std::endl;
	print(first, "first");

	std::cout << "7" << std::endl;
	test = first.erase(first.begin() + 3, first.begin());
	std::cout << "TEST " << *test << std::endl;
	print(first, "first");


	std::cout << "--SWAP--" << std::endl;
	first.swap(second);
	print(first, "first");
	print(second, "second");

	fifth.swap(fourth);
	print(fourth, "fourth");
	print(fifth, "fifth");

	first.clear();
	second.clear();
	third.clear();
	fourth.clear();
	fifth.clear();
}
