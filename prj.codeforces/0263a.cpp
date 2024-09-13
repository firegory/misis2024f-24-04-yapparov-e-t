// ConsoleApplication19.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>


int main()
{
	int n = 0;
	char m = '0';
	while (m != '1')
	{
		std::cin >> m;
		if (m == '0')
		{
			n += 1;
		}
	}
	m += 1;
	int i = 0;
	i = n / 5;
	int j = 0;
	j = n % 5;
	int answ = 0;
	answ = abs(2 - i) + abs(2 - j);
	std::cout << answ;

}

