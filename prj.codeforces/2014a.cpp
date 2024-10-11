#include <iostream> 

int main()
{
	int t = 0;
	std::cin >> t;
	int n = 0;
	int k = 0;
	int sum = 0;
	int money = 0;
	int temp = 0;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n >> k;
		sum = 0;
		money = 0;
		for (int j = 0; j < n; j++)
		{
			std::cin >> temp;
			if (temp >= k)
			{
				money += temp;
			}
			if (temp == 0)
			{
				if (money > 0)
				{
					money--;
					sum++;
				}
			}
		}
		std::cout << sum << "\n";
	}
}

