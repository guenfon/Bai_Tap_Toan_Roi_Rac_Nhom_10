#include <iostream>
#include <string>

using namespace std;

int count = 0;
string s;
void count_bit1_inBinary(int i);

int main()
{
    cin >> s;
    int n = s.size();
    count_bit1_inBinary(n);
    return 0;
}

void count_bit1_inBinary(int i)
{
    if (i == 0)
    {
        cout << count;
        return;
    }
    if (s[i - 1] == '1')
        count++;
    count_bit1_inBinary(i - 1);
}