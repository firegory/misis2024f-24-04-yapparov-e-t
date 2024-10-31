#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
	int n = 0;
	int temp = 0;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		for (int j = 0; j < n; j++)
		{
			std::cin >> temp;
		}
		std::cout << "2\n";
		std::cout << "1 " << n << "\n";
		std::cout << "1 " << n << "\n";
	}
}