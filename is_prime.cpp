#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pnl cout << "\n"
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << (#x) << " " << (x) << "\n"
#else
#define dbg(x) 42
#endif

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = array<int, 2>;
using vii = vector<ii>;

template <typename T>
istream &operator>>(istream &in, vector<T> &a) {
    for (auto &x : a) in >> x;
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &x : a) out << x << " ";
    return out;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
Miller-Rabin primality test
Determnistc for n < 4,759,123,141
Time Complexity: O(log(n)^3)
*/
int safe_mod(int x, int m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}
int pow_mod(int x, int n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned int r = 1;
    unsigned int y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    int d = n - 1;
    while (d % 2 == 0) d /= 2;
    int bases[3] = {2, 7, 61};
    for (int a : bases) {
        int t = d;
        int y = pow_mod(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}

void solve(int testcase) {
    int n; cin >> n;
    if (is_prime(n)) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    using namespace chrono;
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    auto start = high_resolution_clock::now();
    int T = 1; cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() << " ms\n";
#endif
    return 0;
}
