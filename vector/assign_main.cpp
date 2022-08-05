#include "vector.hpp"
#include "print.cpp"

int	main(void)
{
	NAMESPACE::vector<int> mfirst;
	NAMESPACE::vector<int> msecond;
	NAMESPACE::vector<int> mthird;


	mfirst.assign(7, 100);
	msecond.assign(mfirst.begin(), mfirst.end());

	std::cout <<"-----1-----"<< std::endl;
	print(mfirst);
	print(msecond);

	std::cout <<"-----2-----"<< std::endl;
	msecond[1] = 9;
	print(msecond);
	mfirst.assign(msecond.begin(), msecond.begin() + 2);
	print(mfirst);

	std::cout <<"-----3-----"<< std::endl;
	mfirst.assign(4, 10);
	print(mfirst);



	std::cout <<"-----4-----"<< std::endl;
	int	myints[] = {1, 2, 3, 4, 5};
	std::cout << "Size of mthird : " << mthird.size() << std::endl;
	mthird.assign (myints, myints + 5);
	std::cout << "Size of mthird : " << mthird.size() << ' ' << mthird.capacity() << std::endl << std::endl;
	print(msecond);
	print(mthird);

	std::cout <<"-----5-----"<< std::endl;
	NAMESPACE::vector<std::string>		mfourth;
	NAMESPACE::vector<std::string>		mfifth;
	mfourth.assign(3, "Hello !");
	print(mfourth);

	std::cout <<"-----6-----"<< std::endl;
	NAMESPACE::vector<std::string>::const_iterator mcit = mfourth.begin();
	NAMESPACE::vector<std::string>::const_iterator mcite = mfourth.end();
	NAMESPACE::vector<std::string>::iterator mit = mfourth.begin();
	NAMESPACE::vector<std::string>::iterator mite = mfourth.end();
	mfifth.assign(mcit, mcite);
	print(mfifth);

	std::cout <<"-----7-----"<< std::endl;
	mit = mfifth.begin();
	*mit = "HIHI";
	print(mfifth);


//	std::cout << "Size of first : " << first.size() << std::endl;
//	first.assign (7, 100);
//	std::cout << "Size of first : " << first.size() << std::endl << std::endl;
//	
//	std::cout << "Size of second : " << second.size() << std::endl;
//	second.assign (first.begin() + 1, first.end() - 2);
//	std::cout << "Size of second : " << second.size() << std::endl << std::endl;
//	
//	int	myints[] = {1, 2, 3, 4, 5};
//	std::cout << "Size of third : " << third.size() << std::endl;
//	third.assign (myints, myints + 5);
//	std::cout << "Size of third : " << third.size() << ' ' << third.capacity() << std::endl << std::endl;
//
//	print(first);
//	print(second);
//	print(third);
//
//	std::cout << "Size of first : " << first.size() << ' ' << first.capacity() << std::endl << std::endl;
//	first.assign(third.begin(), third.end() - 3);
//	std::cout << "Size of first : " << first.size() << ' ' << first.capacity() << std::endl << std::endl;
//	print(first);
//
//
//	std::cout << "Size of third : " << third.size() << ' ' << third.capacity() << std::endl << std::endl;
//	third.assign(first.begin(), first.end());
//	std::cout << "Size of third : " << third.size() << ' ' << third.capacity() << std::endl << std::endl;

	return (0);
}
