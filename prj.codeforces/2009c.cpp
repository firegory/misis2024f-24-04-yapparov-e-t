// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int x = 0;
    int y = 0;
    int k = 0;
    int stepsX = 0;
    int stepsY = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x >> y >> k;
        stepsX = (x / k) * 2 - 1;
        if (x % k != 0)
        {
            stepsX += 2;
        }
        stepsY = (y / k) * 2;
        if (y % k != 0)
        {
            stepsY += 2;
        }
        if (stepsX > stepsY)
        {
            std::cout << stepsX << "\n";
        }
        else
        {
            std::cout << stepsY << "\n";
        }
    }
}
