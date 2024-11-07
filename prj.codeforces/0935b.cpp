#include <iostream>
#include <vector>


int main()
{
	int n = 0;
	std::cin >> n;
	int answ = 0;
	int x = 0;
	int y = 0;
	char temp = ' ';
	bool side = true;
	std::cin >> temp;
	if (temp == 'U')
	{
		side = true;
		y++;
	}
	else
	{
		side = false;
		x++;
	}
	for (int i = 0; i < n - 1; i++)
	{
		std::cin >> temp;
		if (temp == 'U')
		{
			if (x == y)
			{
				if (!side)
				{
					answ++;
					side = true;
				}
			}
			y++;
		}
		else
		{
			if (x == y)
			{
				if (side)
				{
					answ++;
					side = false;
				}
			}
			x++;
		}
	}
	std::cout << answ;
}