#include <iostream>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
	char temp = ' ';
	std::pair<int, int> point;
	std::pair<int, int> movVector;;
	std::vector<std::vector<char>> field = std::vector<std::vector<char>>(8);
	for (int i = 0; i < 8; i++)
	{
		field[i] = std::vector<char>(8);
	}
	for (int i = 0; i < t; i++)
	{
		point.first = -1;
		point.second = -1;
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				std::cin >> temp;
				field[j][k] = temp;
				if (temp == '#' && point.first == -1 && (j==0 || k ==0))
				{
					point.first = j;
					point.second = k;
				}
			}
		}
		if (point.first == 0 && point.second == 0)
		{
			movVector.first = 1;
			movVector.second = 1;
		}
		else if (point.first == 0)
		{
			if (field[point.first+1][point.second+1] == '#')
			{
				movVector.first = 1;
				movVector.second = 1;
			}
			else
			{
				movVector.first = 1;
				movVector.second = -1;
			}
		}
		else
		{
			if (field[point.first + 1][point.second + 1] == '#')
			{
				movVector.first = 1;
				movVector.second = 1;
			}
			else
			{
				movVector.first = -1;
				movVector.second = 1;
			}
		}
		for (int j = 0; j < 8; j++)
		{
			point.first += movVector.first;
			point.second += movVector.second;
			if (field[point.first + 1][point.second + 1] == '#' && field[point.first - 1][point.second + 1] == '#'&& field[point.first + 1][point.second - 1] == '#'&& field[point.first - 1][point.second - 1] == '#')
			{
				break;
			}
		}
		std::cout << point.first + 1 << " " << point.second + 1 << "\n";
	}
}