#include <iostream>

using namespace std;

int n;
int a[10000];

void print();
void Binary(int i);

int main()
{
    cin >> n;
    Binary(0);
    return 0;
}

void print()
{
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << '\n';
}

void Binary(int i)
{
    if (i == n)
    {
        print();
        return;
    }
    a[i] = 0;
    Binary(i + 1);
    a[i] = 1;
    Binary(i + 1);
}