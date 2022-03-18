#include <bits/stdc++.h>

using namespace std;

int eulerPhi(int n) { // = n (1-1/p1) ... (1-1/pn)
    if (n == 0) return 0;
    int ans = n;
    for (int x = 2; x*x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

int main()
{
    int n = 187;
    int phi_n = eulerPhi(n);
    cout << phi_n << endl;
    /*int d, e = 9;
    // (d*e) mod phi_n = 1 => d = ?
    d = (1 * e) % phi_n;
    cout << d << endl;
    for (d = 1;; ++d)
        if ((d*e) % phi_n == 1) break;
    cout << d << endl;*/
    return 0;
}