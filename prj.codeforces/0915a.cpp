#include <iostream>
#include <vector>


int main()
{
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	int temp = 0;
	int answ = k+1;
	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;
		if (k % temp == 0 && k / temp < answ)
		{
			answ = k/temp;
		}
	}
	std::cout << answ;
}