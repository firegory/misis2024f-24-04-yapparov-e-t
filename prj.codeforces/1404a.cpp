#include <iostream>
#include <cmath>

bool check(int a, int b, int q)
{
    if (a == b || (abs(a - b) <= q && (q - abs(a - b)) % 2 == 0))
    {
        return true;
    }
    return false;
}


int main() {
    int t = 0;
    std::cin >> t;
    int n = 0;
    int k = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    std::string s = "";
    bool usl = true;
    for (int i = 0; i < t; i++)
    {
        usl = true;
        std::cin >> n;
        std::cin >> k;
        std::cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (j >= k)
            {
                if (s[j] == '0')
                {
                    if (s[j % k] == '1')
                    {
                        usl = false;
                        break;
                    }
                    else
                    {
                        s[j % k] = '0';
                    }
                }
                else if (s[j] == '1')
                {
                    if (s[j % k] == '0')
                    {
                        usl = false;
                        break;
                    }
                    else
                    {
                        s[j % k] = '1';
                    }
                }
            }
        }

        if (usl)
        {
            a = 0;
            b = 0;
            c = 0;
            for (int j = 0; j < k; j++)
            {
                if (s[j] == '0')
                {
                    a++;
                }
                else if (s[j] == '1')
                {
                    b++;
                }
                else
                {
                    c++;
                }
            }
            if (check(a, b, c))
            {
                std::cout << "YES\n";
            }
            else
            {
                std::cout << "NO\n";
            }
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}
