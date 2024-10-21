#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    int a = 0;
    int b = 0;
    int temp = 0;
    for (int i = 0; i < t; i++)
    {
        std::cin >> a >> b;
        if (a >= b)
        {
            std::cout << a << "\n";
        }
        else if (2*a <= b)
        {
            std::cout << 0 << "\n";
        }
        else
        {
            std::cout << a - (b - a) << "\n";
        }
    }
}