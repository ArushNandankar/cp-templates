#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define float double
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

const int mod = 1e9 + 7;
struct Mat {
    int n, m;
    vector<vector<int>> a;
    Mat() {}
    Mat(int _n, int _m) {
        n = _n;
        m = _m;
        a.assign(n, vector<int>(m, 0));
    }
    Mat(vector<vector<int>> v) {
        n = v.size();
        m = n ? v[0].size() : 0;
        a = v;
    }
    inline void make_unit() {
        assert(n == m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                a[i][j] = i == j;
        }
    }
    inline Mat operator+(const Mat &b) {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
            }
        }
        return ans;
    }
    inline Mat operator-(const Mat &b) {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
            }
        }
        return ans;
    }
    inline Mat operator*(const Mat &b) {
        assert(m == b.n);
        Mat ans = Mat(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
    inline Mat pow(long long k) {
        assert(n == m);
        Mat ans(n, n), t = a;
        ans.make_unit();
        while (k) {
            if (k & 1)
                ans = ans * t;
            t = t * t;
            k >>= 1;
        }
        return ans;
    }
    inline Mat &operator+=(const Mat &b) { return *this = (*this) + b; }
    inline Mat &operator-=(const Mat &b) { return *this = (*this) - b; }
    inline Mat &operator*=(const Mat &b) { return *this = (*this) * b; }
    inline bool operator==(const Mat &b) { return a == b.a; }
    inline bool operator!=(const Mat &b) { return a != b.a; }
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
