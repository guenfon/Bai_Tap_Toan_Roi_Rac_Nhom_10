#include<iostream>
using namespace std;

int n;

void backtrack(string s, int hieuso);

int main()
{
    cin >> n;
    while (n != 0)
    {
        if (n % 2 == 0)
            backtrack("",0);
        --n;
    }
    return 0;
}

void backtrack(string s, int hieuso)
{
    int l = s.length();
    if(l == n)
        cout << s << '\n';
    if(hieuso < n - l)
        backtrack(s + '(', hieuso + 1);
    if(hieuso > 0)
        backtrack(s + ')', hieuso - 1);
}