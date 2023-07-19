#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int gcd(int a, int b) {
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    if (a >= b) {
        int r = a % b;
        int k = a / b;
        if (k % 2 == 1) {
            return gcd(b, r) + k + k / 2;
        } else {
            return gcd(r, b) + k + k / 2;
        }
    }
    return 1 + gcd(b, abs(a - b));
}
 
int calc(int a, int b) {
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    return 1 + calc(b, abs(a - b));
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        set<int> cnt;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0 && b[i] == 0) {
                continue;
            }
            cnt.insert(gcd(a[i], b[i]) % 3);
        }
        if (cnt.size() <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}