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

// tested on SPOJ
int n;
vi a, freq, freqCnt;
int maxFreq;

void add(int ind) {
    int val = a[ind];
    freqCnt[freq[val]]--;
    freq[val]++;
    freqCnt[freq[val]]++;
    maxFreq = max(maxFreq, freq[val]);
}

void del(int ind) {
    int val = a[ind];
    freqCnt[freq[val]]--;
    freq[val]--;
    if (freqCnt[maxFreq] == 0) maxFreq--;
    freqCnt[freq[val]]++;
}

int calc() {
    return maxFreq;
}

vi mo(vector<ii> Q) {
    int L = 0, R = -1, blk = sqrt(n);
    vi s(sz(Q)), res(sz(Q));
    iota(s.begin(), s.end(), 0);
    #define K(x) ii({x[0] / blk, x[1] ^ - (x[0] / blk & 1)})
    sort(s.begin(), s.end(), [&](int s, int t) -> bool { return K(Q[s]) < K(Q[t]); });
    freq.assign(n + 1, 0); // check this once
    freqCnt.assign(n + 1, 0); // check this once
    maxFreq = 0;

    for (int qi : s) {
        ii q = Q[qi];
        int ql = q[0], qr = q[1];

        while (R < qr) add(++R);
        while (R > qr) del(R--);
        while (L < ql) del(L++);
        while (L > ql) add(--L);

        res[qi] = calc();
    }
    return res;
}
void solve(int testcase) {
    int q; cin >> n >> q;
    a.resize(n); cin >> a;

    vector<ii> queries;

    while (q--) {
        int l, r; cin >> l >> r;
        queries.push_back({l, r});
    }

    vi ans = mo(queries);

    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << "\n";
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
