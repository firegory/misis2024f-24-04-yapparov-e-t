#include <iostream>
#include <cmath>

int main() {
    int t = 0;
    std::cin >> t;
    int l = 0;
    int r = 0;
    int l1 = 0;
    int r1 = 0;
    int ans = 0;
    for (int i = 0; i < t; i++)
    {
        std::cin >> l;
        std::cin >> r;
        std::cin >> l1;
        std::cin >> r1;
        ans = std::min(r,r1) - std::max(l1,l);
        if (ans+1 <= 0)
        {
            std::cout << 1 << "\n";
            continue;
        }
        if (l != l1)
        {
            ans += 1;
        }
        if (r != r1)
        {
            ans += 1;
        }
        std::cout << ans << "\n";
    }
}
