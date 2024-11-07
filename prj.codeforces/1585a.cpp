#include <iostream>
#include <cmath>


int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    int temp = 0;
    int size = 0;
    int prev = 0;
    bool dead = false;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        size = 1;
        dead = false;
        for (int j = 0; j < n; j++)
        {
            std::cin >> temp;
            if (temp == 0)
            {
                if (j > 0)
                {
                    if (prev == 0)
                    {
                        size = -1;
                        dead = true;
                    }
                }
            }
            else
            {
                if (j > 0)
                {
                    if (prev == 1)
                    {
                        size += 4;
                    }
                }
                size += 1;
            }
            prev = temp;
        }
        if (!dead)
        {
            std::cout << size << "\n";
        }
        else
        {
            std::cout << -1 << "\n";
        }
    }
}
