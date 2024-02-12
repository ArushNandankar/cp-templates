#include <bits/stdc++.h>

#define int long long
#define float double
#define all(x) (x).begin(), (x).end()
#define dbg(x) cout << (#x) << " " << (x) << "\n"

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define testcases                \
    int T;                       \
    cin >> T;                    \
    for (int t = 1; t <= T; t++) \

#define pnl cout << "\n"
#define pyes cout << "YES"
#define pno cout << "NO"

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

bool _compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<1>(a) > get<1>(b); // sort queries in descending order of r
}

void solve(int testcase)
{
    int n, q;
    cin >> n >> q;
    map<int, int> compress;
    vi a(n);
    for (auto &x : a) {
        cin >> x;
        compress[x] = 1;
    }
    int count = 0;
    for (auto &x : compress) {
        x.second = count;
        count++;
    }
    for (auto &x : a) {
        x = compress[x];
    }

    int B = sqrt(n) + 1;
    vector<tuple<int, int, int>> queries[n / B + 1];
    vpii anws;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int c = l / B;
        queries[c].push_back({l, r, i});
    }

    for (int i = 0; i <= n / B; i++) {
        sort(all(queries[i]), _compare);
    }

    for (int i = 0; i <= n / B; i++) {
        int L = i * B;
        int R = n - 1;
        vi freq(n + 1);
        int ans = 0;
        for (int j = L; j <= R; j++) {
            if (freq[a[j]] == 0) {
                ans++;
            }
            freq[a[j]]++;
        }
        for (auto [l, r, idx] : queries[i]) {
            for (int j = R; j > r; j--) {
                freq[a[j]]--;
                if (freq[a[j]] == 0) {
                    ans--;
                }
            }
            if (l >= L) {
                for (int j = L; j < l; j++) {
                    freq[a[j]]--;
                    if (freq[a[j]] == 0) {
                        ans--;
                    }
                }
            } else if (l < L) {
                for (int j = L - 1; j >= l; j--) {
                    if (freq[a[j]] == 0) {
                        ans++;
                    }
                    freq[a[j]]++;
                }
            }
            L = l;
            R = r;
            anws.push_back({idx, ans});
        }
    }
    sort(all(anws));
    for (auto &x : anws) {
        cout << x.second << "\n";
    }
}

int32_t main()
{
    fast_io;
    // testcases
    solve(1);
    return 0;
}
