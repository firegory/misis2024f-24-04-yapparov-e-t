#include <iostream>
#include <vector>


int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<int> v = std::vector<int>(n);
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;
		v[temp-1] = i+1;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << v[i] << " ";
	}
}