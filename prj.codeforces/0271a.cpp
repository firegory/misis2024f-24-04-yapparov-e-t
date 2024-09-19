// ConsoleApplication19.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>


int main()
{
	int m = 0;
	std::cin >> m;
	int l[4] = {0};
	bool a = true;
	for (int i = m + 1; i < 9999; i++)
	{
		l[0] = i / 1000;
		l[1] = (i % 1000) / 100;
		l[2] = (i % 100) / 10;
		l[3] = i % 10;
		a = true;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (l[k] == l[j] && k != j)
				{
					a = false;
				}
			}
		}
		if (a)
		{
			std::cout << i;
			break;
		}
	}

}