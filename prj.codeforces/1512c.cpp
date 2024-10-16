#include <iostream>
#include <cmath>


int main() {
    int t = 0;
    std::cin >> t;
    int a = 0;
    int b = 0;
    int aNow = 0;
    int bNow = 0;
    int qNow = 0;
    std::string s = "";
    bool cond = false;
    for (int i = 0; i < t; i++)
    {
        std::cin >> a;
        std::cin >> b;
        std::cin >> s;
        aNow = 0;
        bNow = 0;
        qNow = 0;
        cond = false;
        for (int j = 0; j < (a + b) / 2 + (a + b) % 2; j++)
        {
            if (s[j] == '?')
            {
                if (s[s.size() - 1 - j] == '?')
                {
                    qNow += 1;
                    if (s.size() - 1 - j != j)
                    {
                        qNow += 1;
                    }
                }
                else if (s[s.size() - 1 - j] == '0')
                {
                    s[j] = '0';
                    aNow += 2;
                }
                else
                {
                    s[j] = '1';
                    bNow += 2;
                }
            }
            else if (s[j] == '0')
            {
                if (s[s.size() - 1 - j] == '0')
                {
                    aNow += 1;
                    if (s.size() - 1 - j != j)
                    {
                        aNow += 1;
                    }
                }
                else if (s[s.size() - 1 - j] == '?')
                {
                    aNow += 2;
                    s[s.size() - 1 - j] = '0';
                }
                else
                {
                    cond = true;
                    break;
                }
            }
            else
            {
                if (s[s.size() - 1 - j] == '1')
                {
                    bNow += 1;
                    if (s.size() - 1 - j != j)
                    {
                        bNow += 1;
                    }
                }
                else if (s[s.size() - 1 - j] == '?')
                {
                    bNow += 2;
                    s[s.size() - 1 - j] = '1';
                }
                else
                {
                    cond = true;
                    break;
                }
            }

        }
        if (cond)
        {
            std::cout << "-1\n";
        }
        else
        {
            if (aNow > a || bNow > b)
            {
                std::cout << "-1\n";
            }
            else
            {
                if ((a % 2 != aNow % 2 && qNow % 2 != 1) || (b % 2 != bNow % 2 && qNow % 2 != 1))
                {
                    std::cout << "-1\n";
                }
                else
                {
                    for (int j = 0; j < (a + b) / 2 + (a + b) % 2; j++)
                    {
                        if (s[j] == '?')
                        {
                            if (j == (a + b) / 2)
                            {
                                if (aNow % 2 != a % 2)
                                {
                                    s[j] = '0';
                                    aNow += 1;
                                }
                                else
                                {
                                    s[j] = '1';
                                    bNow += 1;
                                }
                            }
                            else if (aNow + 1 < a)
                            {
                                s[j] = '0';
                                s[s.size() - 1 - j] = '0';
                                aNow += 2;
                            }
                            else
                            {
                                s[j] = '1';
                                s[s.size() - 1 - j] = '1';
                                bNow += 2;
                            }
                        }
                    }
                    std::cout << s << "\n";
                }
            }
        }
    }
}
