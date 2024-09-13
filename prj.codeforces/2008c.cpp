// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int adder = 0;
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> l >> r;
        adder = 1;
        while (l <= r)
        {
            l += adder;
            adder += 1;
        }
        std::cout << adder - 1 << "\n";
    }
}
