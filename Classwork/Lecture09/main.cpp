#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Iterator.h"

#include <iostream>
#include "Stack.h"

int main()
{
	srand(time(NULL));
	std::string letters = "abcdefghijklmnopqrstuvwxyz";

	ds::da::Stack<char> S;
	ds::sn::Stack<char> T;

	for(int i = 0;i < 26;i += 1)
	{
		S.Push(letters[i]);
		T.Push(letters[i]);
	}

	std::cout << "alphabet: " << letters << "\n"; 
	std::cout << "alphabet in reverse generated by S: ";

	while(!S.IsEmpty())
	{
		std::cout << S.Top();
		S.Pop();
	}

	std::cout << "\n";  

	std::cout << "alphabet in reverse generated by T: ";

	while(!T.IsEmpty())
	{
		std::cout << T.Top();
		T.Pop();
	}

	std::cout << "\n";  

	return 0;
}
