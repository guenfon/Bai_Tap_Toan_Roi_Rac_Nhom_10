#include <iostream>

using namespace std;

void Binary_Insertion_Sort(int *a, int n);

int main()
{
    int n;
    cin >> n;
    int *a = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Binary_Insertion_Sort(a, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}

void Binary_Insertion_Sort(int *a, int n)
{
    for (int i = 2; i <= n; i++)
    {
        int x = a[i];
        int low = 1;
        int high = i - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (a[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (int j = i - 1; j >= low; j--)
            a[j + 1] = a[j];
        a[low] = x;
    }
}