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

struct FenwickTree {
    vi s;
    FenwickTree(int n) : s(n) {}
    void update(int pos, int dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    int query(int pos) { // sum of values in [0, pos)
        int res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
        return res;
    }
    int lower_bound(int sum) { // min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};
struct FT2 {
    vector<vi> ys; vector<FenwickTree> ft;
    FT2(int limx) : ys(limx) {}
    void fakeUpdate(int x, int y) {
        for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
    }
    void init() {
        for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
    }
    int ind(int x, int y) { return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
    void update(int x, int y, int dif) {
        for (; x < sz(ys); x |= x + 1)
            ft[x].update(ind(x, y), dif);
    }
    int query(int x, int y) {
        if (!x || !y) return 0;
        int sum = 0;
        for (; x; x &= x - 1)
            sum += ft[x - 1].query(ind(x - 1, y));
        return sum;
    }
};

void solve(int testcase) {
    int n, q; scanf("%d %d", &n, &q);
    char s[n][n];
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    vvi a(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            a[i][j] = (s[i][j] == '*');
        }
    }
    FT2 ft(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ft.fakeUpdate(i, j);
        }
    }
    ft.init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) ft.update(i, j, 1);
        }
    }
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int x, y; scanf("%d %d", &x, &y);
            --x, --y;
            if (a[x][y]) {
                a[x][y] = 0;
                ft.update(x, y, -1);
            } else {
                a[x][y] = 1;
                ft.update(x, y, 1);
            }
        } else {
            int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            --x1, --y1, --x2, --y2;
            cout << ft.query(x2 + 1, y2 + 1) - ft.query(x1, y2 + 1) - ft.query(x2 + 1, y1) + ft.query(x1, y1) << "\n";
        }
    }
}

int32_t main() {
    using namespace chrono;
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    auto start = high_resolution_clock::now();
    int T = 1; // cin >> T;
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