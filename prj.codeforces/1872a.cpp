#include <iostream>
#include <cmath>

int main()
{
    int n = 0;
    std::cin >> n;
    int a = 0;
    int b = 0;
    int c = 0;
    int dif = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b >> c;
        c = c * 2;
        dif = abs(a - b);
        ans = dif / c;
        if (dif % c != 0) {
            ans += 1;
        }
        std::cout << ans << "\n";
    }
}