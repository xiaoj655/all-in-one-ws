#include<bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

int gcd(int a, int b) {
    if (a == 1 || b == 1) {
        return 1;
    }
    if (a > b) {
        swap(a, b);
    }
    for (int i = a; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

bool can_second_player_win(int n, int a, int b) {
    if (a == 1 || b == 1) {
        return true;
    }
    if (gcd(a, b) != 1) {
        return true;
    }
    if (n % (a + b) <= a) {
        return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        int x = lcm(a, b) / gcd(a, b);
        for (int i = 1; ; i++) {
            if (can_second_player_win(i * x, a, b)) {
                cout << i * x << endl;
                break;
            }
        }
    }
    return 0;
}
