#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        if (n%2==0)
        {
            std::cout << "Sakurako\n";
        }
        else
        {
            std::cout << "Kosuke\n";
        }
    }
}