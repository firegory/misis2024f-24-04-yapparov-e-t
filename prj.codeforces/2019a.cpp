#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    int temp = 0;
    int max1 = 0;
    int max2 = 0;
    int l = 0;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        max1 = -1;
        max2 = -1;
        l = 0;
        for (int j = 0; j < n; j++)
        {
            std::cin >> temp;
            if (l % 2 == 0)
            {
                if (temp > max1)
                {
                    max1 = temp;
                }
            }
            else
            {
                if (temp > max2)
                {
                    max2 = temp;
                }
            }
            l += 1;
        }
        if (max1 + (l / 2) + (l % 2) > max2 + (l / 2))
        {
            std::cout << max1 + (l / 2) + (l % 2) << "\n";
        }
        else
        {
            std::cout << max2 + (l / 2) << "\n";
        }
    }
}
