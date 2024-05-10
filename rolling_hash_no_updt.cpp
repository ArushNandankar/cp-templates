#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int int
#define float double
#define all(x) (x).begin(), (x).end()
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
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

using T = array<int, 3>;
const T MOD = {1000000007, 1000000009, 1000000021};
const T p = {101, 211, 307};

T operator+(T a, int x) { return {(a[0] + x) % MOD[0], (a[1] + x) % MOD[1], (a[2] + x) % x}; }
T operator-(T a, int x) { return {(a[0] - x + MOD[0]) % MOD[0], (a[1] - x + MOD[1]) % MOD[1], (a[2] - x + MOD[2]) % MOD[2]}; }
T operator*(T a, int x) { return {(int)((int)a[0] * x % MOD[0]), (int)((int)a[1] * x % MOD[1]), (int)((int)a[2] * x % MOD[2])}; }
T operator+(T a, T x) { return {(a[0] + x[0]) % MOD[0], (a[1] + x[1]) % MOD[1], (a[2] + x[2]) % MOD[2]}; }
T operator-(T a, T x) { return {(a[0] - x[0] + MOD[0]) % MOD[0], (a[1] - x[1] + MOD[1]) % MOD[1], (a[2] - x[2] + MOD[2]) % MOD[2]}; }
T operator*(T a, T x) { return {(int)((int)a[0] * x[0] % MOD[0]), (int)((int)a[1] * x[1] % MOD[1]), (int)((int)a[2] * x[2] % MOD[2])}; }
ostream &operator<<(ostream &os, T hash) { return os << "(" << hash[0] << ", " << hash[1] << ", " << hash[2] << ")"; }

const int N = 4e6 + 9;
int power(int n, int k, const int mod) {
	int ans = 1 % mod;
	n %= mod;
	if (n < 0)
		n += mod;
	while (k) {
		if (k & 1)
			ans = (int)ans * n % mod;
		n = (int)n * n % mod;
		k >>= 1;
	}
	return ans;
}
T pw[N], ipw[N];
void prec() {
    pw[0] = {1, 1, 1};
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * p;
    }
    ipw[0] = {1, 1, 1};
    T ip = {power(p[0], MOD[0] - 2, MOD[0]), power(p[1], MOD[1] - 2, MOD[1]), power(p[2], MOD[2] - 2, MOD[2])};
    for (int i = 1; i < N; i++) {
        ipw[i] = ipw[i - 1] * ip;
    }
}

struct Hashing {
    vector<T> h1; // forward hash
    vector<T> h2; // backward hash
    Hashing(string s) {
        int n = s.size();
        h1.resize(n + 1);
        h2.resize(n + 2);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = h1[i] * p + s[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            h2[i] = h2[i + 1] * p + s[i];
        }
    }
    T get_hash(int l, int r) {
        return (h1[r] - h1[l] * pw[r - l]) + (h2[l] - h2[r] * pw[r - l]);
    }
    T get_rev_hash(int l, int r) {
        return (h2[r] - h2[l] * pw[r - l]) + (h1[l] - h1[r] * pw[r - l]);
    }
    bool is_palindrome(int l, int r) {
        return (get_hash(l, r) == get_rev_hash(l, r));
    }
};

void solve(int testcase) {
    
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
