#include <iostream>
#include <cmath>


int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    std::pair<int, int> p1;
    std::pair<int, int> p2;
    std::pair<int, int> p3;
    std::pair<int, int> p4;
    char temp = ' ';
    for (int i = 0; i < t; i++)
    {
        p1.first = -1;
        p1.second = -1;
        p2.first = -1;
        p3.second = -1;
        std::cin >> n;
        for (int j = 0; j < n*n; j++)
        {
            std::cin >> temp;
            if (temp == '*')
            {
                if (p1.first == -1)
                {
                    p1.first = j / n;
                    p1.second = j % n;
                }
                else
                {
                    p2.first = j / n;
                    p2.second = j % n;
                }
            }
        }
        if (p1.first == p2.first)
        {
            if (p1.first == 0)
            {
                p3.first = 1;
                p4.first = 1;
            }
            else
            {
                p3.first = 0;
                p4.first = 0;
            }
            p3.second = p1.second;
            p4.second = p2.second;
        }
        else if (p1.second == p2.second)
        {
            if (p1.second == 0)
            {
                p3.second = 1;
                p4.second = 1;
            }
            else
            {
                p3.second = 0;
                p4.second = 0;
            }
            p3.first = p1.first;
            p4.first = p2.first;
        }
        else
        {
            p3.first = p1.first;
            p3.second = p2.second;
            p4.first = p2.first;
            p4.second = p1.second;
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((j == p1.first && k == p1.second) || (j == p2.first && k == p2.second) || (j == p3.first && k == p3.second) || (j == p4.first && k == p4.second))
                {
                    std::cout << '*';
                }
                else
                {
                    std::cout << '.';
                }
            }
            std::cout << "\n";
        }
    }
}
