#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
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

struct SuffixArray {
    string ss;
    vi sa, lcp;
    SuffixArray(const string &s, int lim = 256) {
        ss = s;
        int n = s.size() + 1, k = 0, a, b;
        vi x(all(s) + 1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1LL, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            for (int i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            for (int i = 0; i < n; i++) ws[x[i]]++;
            for (int i = 1; i < lim; i++) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++) a = sa[i - 1], b = sa[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 1; i < n; i++) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
        for (k && k--, j = sa[rank[i] - 1];
        s[i + k] == s[j + k]; k++);
    }
    int lower_bound(const string &t) {
        int l = 1, r = sa.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (t <= ss.substr(sa[m], t.size())) r = m;
            else l = m + 1;
        }
        return l;
    }
    int upper_bound(const string &t) {
        int l = 1, r = sa.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (t < ss.substr(sa[m], t.size())) r = m;
            else l = m + 1;
        }
        return l;
    }
    bool is_substring(const string &t) {
        int l = lower_bound(t);
        int r = upper_bound(t);
        return r - l > 0;
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
