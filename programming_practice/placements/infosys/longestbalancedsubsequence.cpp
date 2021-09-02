#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int open = 0, closed = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            open++;
        else {
            if (open == 0)
                closed++;
            else
                open--;
        }
    }
    cout << s.size() - open - closed;
    return 0;
}
