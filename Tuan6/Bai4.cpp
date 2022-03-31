//backtrack reverse(S);
#include <iostream>
#include <string>

using namespace std;

string Reverse(string s);

int main()
{
    string s;
    cin >> s;
    cout << Reverse(s);
    return 0;
}

string Reverse(string s)
{
    if (s.length() == 1)
        return s;
    return Reverse(s.substr(1)) + s[0];
}