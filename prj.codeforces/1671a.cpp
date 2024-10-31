#include <iostream>
#include <string>

int main() {
    int t = 0;
    std::cin >> t;
	std::string s = "";
	int counter = 0;
	for (int i = 0; i < t; i++)
	{
		std::cin >> s;
		counter = 1;
		for (int j = 1; j < s.length(); j++)
		{
			if (s[j] != s[j - 1])
			{
				if (counter == 1)
				{
					break;
				}
				counter = 1;
			}
			else
			{
				counter++;
			}
		}
		if (counter == 1)
		{
			std::cout << "NO\n";
		}
		else
		{
			std::cout << "YES\n";
		}
	}
}