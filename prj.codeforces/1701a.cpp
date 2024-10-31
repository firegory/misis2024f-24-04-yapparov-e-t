#include <iostream>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
	std::vector<int> v;
	int temp = 0;
	for (int i = 0; i < t; i++)
	{
		v.clear();
		for (int j = 0; j < 4; j++)
		{
			std::cin >> temp;
			v.push_back(temp);
		}
		if (v[0] == 1 && v[1] == 1 && v[2] == 1 && v[3] == 1)
		{
			std::cout << "2\n";
		}
		else if (v[0] == 0 && v[1] == 0 && v[2] == 0 && v[3] == 0)
		{
			std::cout << "0\n";
		}
		else
		{
			std::cout << "1\n";
		}
	}
}