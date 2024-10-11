#include <iostream> 
#include <vector> 

//ВНИМАНИЕ
//Задача, как оказалось, когда я ее дописал, проверяется только на kotlin, кроме как на первом тесте проверена не была!
int main()
{
	int t = 0;
	std::cin >> t;
	int n = 0;
	std::vector<int> v = std::vector<int>();
	bool swapped = false;
	for (int k = 0; k < t; k++)
	{
		v.clear();
		std::cin >> n;
		for (int j = 0; j < n; j++)
		{
			v.push_back(j + 1);
		}


		for (int i = 0; i < n - 1; i++) {
			swapped = false;
			for (int j = 0; j < n - i - 1; j++) {
				if (v[j] % v[j + 1] == 0)
				{
					if (v[j] > v[j + 1]) {
						std::swap(v[j], v[j + 1]);
						swapped = true;
					}
				}
				else if (v[j + 1] % v[j] == 0)
				{
					if (v[j] < v[j + 1]) {
						std::swap(v[j], v[j + 1]);
						swapped = true;
					}
				}
				if (v[j] % v[j + 1] != 0)
				{
					if (v[j] < v[j + 1]) {
						std::swap(v[j], v[j + 1]);
						swapped = true;
					}
				}
				else if (v[j + 1] % v[j] != 0)
				{
					if (v[j] > v[j + 1]) {
						std::swap(v[j], v[j + 1]);
						swapped = true;
					}
				}
			}

			if (!swapped)
				break;
		}
		for (int j = 0; j < n; j++)
		{
			std::cout << v[j] << " ";
		}
		std::cout << "\n";

	}
}

