#include <iostream>
#include <string>

using namespace std;

string s;

void number_min_string(int i);

int main()
{
    cin >> s;
    int n = s.size();
    number_min_string(n);
    return 0;
}

void number_min_string(int i)
{
    if (i == 0)
    {
        return;
    }
    else
    {
        int j = s[i - 1] - '0';
        if (j == 0)
        {
            cout << s[i - 1];
            number_min_string(i - 1);
        }
        else
        {
            number_min_string(i - 1);
            cout << s[i - 1];
        }
    }
}