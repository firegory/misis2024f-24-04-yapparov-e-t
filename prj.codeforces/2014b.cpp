#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    int k = 0;
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::cin >> k;
        sum = 0;
        sum += k / 2;
        if (k%2 != 0 && n %2 != 0)
        {
            sum++;
        }
        if (sum%2 == 0)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}