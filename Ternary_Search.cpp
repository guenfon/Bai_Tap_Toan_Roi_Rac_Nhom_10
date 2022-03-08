#include <iostream>

using namespace std;

const int oo = -0x3f3f3f3f;

//Ternary Search x in arr[1...n]

int Ternary_Search(int x, int *a, int n);

int main()
{
    int n, x;
    cin >> n >> x;
    int *a = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int answer = Ternary_Search(x, a, n);
    if (answer == oo)
        cout << "Not Found";
    else
        cout << "Found at " << answer;
    return 0;
}

int Ternary_Search(int x, int *a, int n)
{
    int low = 1;
    int high = n;
    int mid1, mid2;
    while (low <= high)
    {
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;
        if (a[mid1] == x)
        {
            return mid1;
        }
        else if (a[mid2] == x)
        {
            return mid2;
        }
        else if (a[mid1] > x)
            high = mid1 - 1;
        else if (a[mid2] < x)
            low = mid2 + 1;
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return oo;
}