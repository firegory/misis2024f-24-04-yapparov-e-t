// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int f = 0;
    int t = 0;
    int max = INT_MIN;
    int udov = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> f >> t;
        if (t > k)
        {
            udov = f - (t - k);
        }
        else
        {
            udov = f;
        }
        if (udov > max)
        {
            max = udov;
        }
    }
    std::cout << max;
}
