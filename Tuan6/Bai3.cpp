#include <iostream>
#include <string>

using namespace std;

int m(string s, int n);

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    cout << m(s, n);
    return 0;
}

int m(string s, int n)
{
    if (n == 1)
        return s[0] - '0';
    int Min = m(s, n - 1);
    if (Min > s[n - 1] - '0')
        return s[n - 1] - '0';
    return Min;
}