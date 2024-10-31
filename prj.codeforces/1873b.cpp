#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	int n = 0;
	std::vector<int> v;
	int temp = 0;
	int min = 10;
	int ind = 0;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		min = 10;
		ind = 0;
		v.clear();
		for (int j = 0; j < n; j++)
		{
			std::cin >> temp;
			v.push_back(temp);
			if (min > temp)
			{
				ind = j;
				min = temp;
			}
		}
		v[ind] += 1;
		temp = 1;
		for (int j = 0; j < n; j++)
		{
			temp *= v[j];
		}
		std::cout << temp << "\n";
	}
}