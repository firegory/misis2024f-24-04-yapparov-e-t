#include <iostream>


int main()
{
	int m = 0;
	std::cin >> m;
	if (m % 2 == 0 && m >= 4)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
}