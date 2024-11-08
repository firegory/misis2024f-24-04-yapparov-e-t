#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
	int n = 0;
	int m = 0;
	char temp = ' ';
	std::pair<int, int> minX;
	std::pair<int, int> minY;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		std::cin >> m;
		minX.first = 5;
		minY.second = 5;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				std::cin >> temp;
				if (temp == 'R')
				{
					if (j < minX.first)
					{
						minX.first = j;
						minX.second = k;
					}
					if (k < minY.second)
					{
						minY.first = j;
						minY.second = k;
					}
				}
			}
		}
		if (minX.first != minY.first && minX.second != minY.second)
		{
			std::cout << "NO\n";
		}
		else
		{
			std::cout << "YES\n";
		}
	}
}