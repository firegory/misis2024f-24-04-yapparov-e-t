#include <iostream>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
	int n = 0;
	int counter = 0;
	int temp = 0;
	std::vector<int> v;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		counter = 0;
		v = std::vector<int>(n);
		for (int j = 0; j < n; j++)
		{
			std::cin >> temp;
			v[j] = temp;
			if (temp == 0)
			{
				counter--;
			}
		}
		if (counter < 0)
		{
			std::cout << n + counter << "\n";
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = j+1; k < n; k++)
				{
					if (v[j] == v[k])
					{
						counter = -1;
						break;
					}
				}
				if (counter == -1)
				{
					-1;

				}
			}
			std::cout << n + counter + 1 << "\n";
		}
	}
}