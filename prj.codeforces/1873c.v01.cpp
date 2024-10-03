#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
    int sum = 0;
    char a = ' ';
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 5 - std::max(std::max(4 - j % 10, j % 10 - 5), std::max(4 - j / 10, j / 10 - 5));
            }
        }
        std::cout << sum << "\n";
        sum = 0;
    }
}