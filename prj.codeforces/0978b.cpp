#include <vector>
#include <iostream>
#include <cmath>
#include <string>

int main() {
    using namespace std;
    int n = 0;
    cin >> n;
    string s = "";
    cin >> s;
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
    cout << answ;
}