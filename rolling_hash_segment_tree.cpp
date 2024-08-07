#include <bits/stdc++.h>

#define int long long
#define float double
#define all(x) (x).begin(), (x).end()
#define dbg(x) cout << (#x) << " " << (x) << "\n"
#define pnl cout << "\n"

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)
#define testcases \
    int T;        \
    cin >> T;     \
    for (int t = 1; t <= T; t++)

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

// 1 indexed

const int N = 4e5 + 9;
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

using T = array<int, 2>;
const T MOD = {127657753, 987654319};
const T p = {137, 277};

T operator+(T a, int x) { return {(a[0] + x) % MOD[0], (a[1] + x) % MOD[1]}; }
T operator-(T a, int x) { return {(a[0] - x + MOD[0]) % MOD[0], (a[1] - x + MOD[1]) % MOD[1]}; }
T operator*(T a, int x) { return {(int)((int)a[0] * x % MOD[0]), (int)((int)a[1] * x % MOD[1])}; }
T operator+(T a, T x) { return {(a[0] + x[0]) % MOD[0], (a[1] + x[1]) % MOD[1]}; }
T operator-(T a, T x) { return {(a[0] - x[0] + MOD[0]) % MOD[0], (a[1] - x[1] + MOD[1]) % MOD[1]}; }
T operator*(T a, T x) { return {(int)((int)a[0] * x[0] % MOD[0]), (int)((int)a[1] * x[1] % MOD[1])}; }
ostream &operator<<(ostream &os, T hash) { return os << "(" << hash[0] << ", " << hash[1] << ")"; }

T pw[N], ipw[N];
void prec() {
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * p;
    }
    ipw[0] = {1, 1};
    T ip = {power(p[0], MOD[0] - 2, MOD[0]), power(p[1], MOD[1] - 2, MOD[1])};
    for (int i = 1; i < N; i++) {
        ipw[i] = ipw[i - 1] * ip;
    }
}
struct Hashing {
    int n;
    string s;              // 1 - indexed
    vector<array<T, 2>> t; // (normal, rev) hash
    array<T, 2> merge(array<T, 2> l, array<T, 2> r) {
        l[0] = l[0] + r[0];
        l[1] = l[1] + r[1];
        return l;
    }
    void build(int node, int b, int e) {
        if (b == e) {
            t[node][0] = pw[b] * s[b];
            t[node][1] = pw[n - b + 1] * s[b];
            return;
        }
        int mid = (b + e) >> 1, l = node << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[node] = merge(t[l], t[r]);
    }
    void upd(int node, int b, int e, int i, char x) {
        if (b > i || e < i)
            return;
        if (b == e && b == i) {
            t[node][0] = pw[b] * x;
            t[node][1] = pw[n - b + 1] * x;
            return;
        }
        int mid = (b + e) >> 1, l = node << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[node] = merge(t[l], t[r]);
    }
    array<T, 2> query(int node, int b, int e, int i, int j) {
        if (b > j || e < i)
            return {T({0, 0}), T({0, 0})};
        if (b >= i && e <= j)
            return t[node];
        int mid = (b + e) >> 1, l = node << 1, r = l | 1;
        return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }
    Hashing() {}
    Hashing(string _s) {
        n = _s.size();
        s = "." + _s;
        t.resize(4 * n + 1);
        build(1, 1, n);
    }
    void upd(int i, char c) {
        upd(1, 1, n, i, c);
        s[i] = c;
    }
    T get_hash(int l, int r) { // 1 - indexed
        return query(1, 1, n, l, r)[0] * ipw[l - 1];
    }
    T rev_hash(int l, int r) { // 1 - indexed
        return query(1, 1, n, l, r)[1] * ipw[n - r];
    }
    T get_hash() {
        return get_hash(1, n);
    }
    bool is_palindrome(int l, int r) {
        return get_hash(l, r) == rev_hash(l, r);
    }
};

void solve(int testcase)
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    prec();
    Hashing rs(s);
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int k;
            char x;
            cin >> k >> x;
            rs.upd(k, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            if (rs.is_palindrome(l, r))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}

int32_t main()
{
    fast_io;
    // testcases
    solve(0);
    return 0;
}
