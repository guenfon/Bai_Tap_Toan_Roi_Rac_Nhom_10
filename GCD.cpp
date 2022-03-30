#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if (a > b) swap(a, b);
    if (a == 0) return b;
    if (a % 2 == 0 && b % 2 == 0) return 2 * GCD(a / 2, b / 2);
    if (a % 2 == 0 && b % 2 != 0) return GCD(a / 2, b);
    return GCD(a, b - a); 
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b);
    return 0;
}