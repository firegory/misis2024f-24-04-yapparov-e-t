#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    int r = 0;
    int temp = 0;
    int placesLeft = 0;
    int aloneSits = 0;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n >> r;
        placesLeft = r * 2;
        aloneSits = 0;
        for (int j = 0; j < n; j++)
        {
            std::cin >> temp;
            placesLeft -= (temp - temp % 2);
            aloneSits += temp % 2;
        }
        if (aloneSits <= placesLeft/2)
        {
            std::cout << (r * 2) - placesLeft + aloneSits << "\n";
        }
        else
        {
            std::cout << (r * 2) - placesLeft + aloneSits - (aloneSits - placesLeft / 2) * 2 << "\n";
        }
    }
}