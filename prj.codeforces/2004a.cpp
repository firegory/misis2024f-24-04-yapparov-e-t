#include <iostream> 

int main()
{
	int t = 0;
	std::cin >> t;
	int n = 0;
	int a = 0;
	int b = 0;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		if (n > 2)
		{
			for (int j = 0; j < n; j++)
			{
				std::cin >> a;
			}
			std::cout << "NO\n";
		}
		else
		{
			std::cin >> a >> b;
			if (b - a > 1)
			{
				std::cout << "YES\n";
			}
			else
			{
				std::cout << "NO\n";
			}
		}
	}
}

