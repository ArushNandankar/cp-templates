#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <atcoder/modint>

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

using mint = atcoder::modint998244353;
template <typename T = mint>
struct combinatorics {
    vector<T> fact, ifact;
    combinatorics(int n) : fact(n + 1), ifact(n + 1) {
        assert(n >= 0);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = 1 / fact[n];
        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;
    }
    T nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * ifact[r] * ifact[n - r];
    }
    T nPr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * ifact[n - r];
    }
};
combinatorics comb(2e6 + 5);

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
