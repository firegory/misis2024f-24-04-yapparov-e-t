#include <iostream>
#include <cmath>
#include <vector>

int main() {
    long long m = 0;
    int n = 0;
    std::cin >> m;
    std::cin >> n;
    long long at = 1;
    long long to = 0;
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> to;
        if (to >= at)
        {
            count += to - at;
        }
        else
        {
            count += m + to - at;
        }
        at = to;
    }
    std::cout << count;
}