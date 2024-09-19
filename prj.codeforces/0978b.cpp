#include <iostream>
#include <string>

int main() {
    int n = 0;
    std::cin >> n;
    std::string s = "";
    std::cin >> s;
    int countX = 0;
    int answ = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x')
        {
            countX += 1;
            if (countX >= 3)
            {
                answ += 1;
            }
        }
        else
        {
            countX = 0;
        }
    }
    std::cout << answ;
}