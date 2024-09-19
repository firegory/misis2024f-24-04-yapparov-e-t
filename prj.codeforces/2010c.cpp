#include <iostream>
#include <string>

int main() {
    std::string s = "";
    std::cin >> s;
    bool a = false;
    int const l = s.length();
    for (int i = 1; i < l / 2 + l % 2; i++)
    {
        if (s[0] == s[i])
        {
            a = true;
            for (int j = 1; j < l - i; j++)
            {
                if (s[j] != s[i + j])
                {
                    a = false;
                    break;
                }
            }
            if (a)
            {
                std::cout << "YES\n";
                for (int j = i; j < l; j++)
                {
                    std::cout << s[j];
                }
                break;
            }
        }
    }
    if (!a)
    {
        std::cout << "NO";
    }
}