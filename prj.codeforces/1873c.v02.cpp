#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
    int sum = 0;
    char a = ' ';
    int j = 0;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 1;
            }
        }
        for (j = 0; j < 8; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 2;
            }
        }
        for (j = 0; j < 2; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 1;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        for (j = 0; j < 6; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 3;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        for (j = 0; j < 2; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 1;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 3;
        }
        for (j = 0; j < 4; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 4;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 3;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        for (j = 0; j < 2; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 1;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 3;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 4;
        }
        for (j = 0; j < 2; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 5;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 4;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 3;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        for (j = 0; j < 2; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 1;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 3;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 4;
        }
        for (j = 0; j < 2; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 5;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 4;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 3;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        for (j = 0; j < 2; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 1;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 3;
        }
        for (j = 0; j < 4; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 4;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 3;
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        for (j = 0; j < 2; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 1;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        for (j = 0; j < 6; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 3;
            }
        }
        std::cin >> a;
        if (a == 'X')
        {
            sum += 2;
        }
        for (j = 0; j < 2; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 1;
            }
        }
        for (j = 0; j < 8; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 2;
            }
        }
        for (j = 0; j < 11; j++)
        {
            std::cin >> a;
            if (a == 'X')
            {
                sum += 1;
            }
        }
        std::cout << sum << "\n";
        sum = 0;
    }
}