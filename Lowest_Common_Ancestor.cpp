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

vi depth;
template <typename T, typename QueryType = function<T(T, T)>>
class SparseTable {
private:
    vector<vector<T>> table;
    vector<int> log;
    int n;
    QueryType queryOp;
public:
    SparseTable(const vector<T> &input, const QueryType &queryOp) : queryOp(queryOp) {
        n = input.size();
        int maxLog = log2(n) + 1;
        table.resize(n, vector<T>(maxLog));
        log.resize(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++)
            log[i] = log[i / 2] + 1;
        for (int i = 0; i < n; ++i)
            table[i][0] = input[i];
        for (int j = 1; j < maxLog; ++j)
            for (int i = 0; i + (1 << j) <= n; ++i)
                table[i][j] = queryOp(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
    T query(int l, int r) {
        assert(l <= r);
        assert(l >= 0);
        assert(r < n);
        int j = log[r - l + 1];
        return queryOp(table[l][j], table[r - (1 << j) + 1][j]);
    }
};

void solve(int testcase) {
    cout << "Case " << testcase << ":\n";
    int n; cin >> n;
    vvi adj(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int u; cin >> u; --u;
            adj[u].push_back(i);
            adj[i].push_back(u);
        }
    }

    vi euler;
    vi first(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        euler.push_back(v);
        first[v] = euler.size() - 1;
        for (auto &u : adj[v]) {
            if (u == p) continue;
            dfs(u, v);
            euler.push_back(v);
        }
    };
    dfs(0, -1);

    depth.resize(n);
    function<void(int, int, int)> dfs2 = [&](int v, int p, int d) {
        depth[v] = d;
        for (auto &u : adj[v]) {
            if (u == p) continue;
            dfs2(u, v, d + 1);
        }
    };
    dfs2(0, -1, 0);

    SparseTable<int> t(euler, [](int x, int y) { 
        if (depth[x] < depth[y]) return x;
        return y;
    });

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        --u, --v;
        int idx1 = min(first[u], first[v]);
        int idx2 = max(first[u], first[v]);
        cout << t.query(idx1, idx2) + 1; pnl;
    }
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
