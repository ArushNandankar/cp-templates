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

class Tree {
private:
    vvi adj;
    int n;
    vvi ancestors;
    bool pre_preocessed = false;
public:
    Tree(vvi &adj) {
        this->adj = adj;
        this->n = adj.size();
    }
    tuple<int, int, int> get_diameter() {
        int end1 = -1;
        int max_dis1 = -1;
        function<void(int, int, int)> dfs_depth = [&](int v, int p, int depth) {
            if (depth > max_dis1) {
                end1 = v;
                max_dis1 = depth;
            }
            for (auto u : adj[v]) {
                if (u == p) continue;
                dfs_depth(u, v, depth + 1);
            }
        };
        dfs_depth(0, -1, 0);
        int end2 = -1;
        int diameter = -1;
        function<void(int, int, int)> dfs_depth2 = [&](int v, int p, int depth) {
            if (depth > diameter) {
                end2 = v;
                diameter = depth;
            }
            for (auto u : adj[v]) {
                if (u == p) continue;
                dfs_depth2(u, v, depth + 1);
            }
        };
        dfs_depth2(end1, -1, 0);
        return {diameter, end1, end2};
    };
    vi max_distances() {
        vi dist(n);
        auto [diameter, end1, end2] = get_diameter();
        vector<bool> vis(n); queue<pii> q1;
        vis[end1] = true; q1.push({end1, 0});
        while (!q1.empty()) {
            auto [v, d] = q1.front(); q1.pop();
            dist[v] = max(dist[v], d);
            for (auto u : adj[v]) {
                if (vis[u]) continue;
                vis[u] = true;
                q1.push({u, d + 1});
            }
        }
        vector<bool> vis2(n); queue<pii> q2;
        vis2[end2] = true; q2.push({end2, 0});
        while (!q2.empty()) {
            auto [v, d] = q2.front(); q2.pop();
            dist[v] = max(dist[v], d);
            for (auto u : adj[v]) {
                if (vis2[u]) continue;
                vis2[u] = true;
                q2.push({u, d + 1});
            }
        }
        return dist;
    }
    vi subtree() {
        vi kids(n);
        function<void(int, int)> dfs = [&](int v, int p) -> void {
            kids[v] = 1;
            for (auto u : adj[v]) {
                if (u == p) continue;
                dfs(u, v);
                kids[v] += kids[u];
            }
        };
        dfs(0, -1);
        return kids;
    }
    vvi layers() { // root is 0
        vvi layers(n);
        vi visited(n);
        queue<pii> q;
        visited[0] = 1; q.push({0, 0});
        while (!q.empty()) {
            auto [v, dis] = q.front(); q.pop();
            layers[dis].push_back(v);
            for (auto &u : adj[v]) {
                if (visited[u]) continue;
                visited[u] = 1; q.push({u, dis + 1});
            }
        }
        return layers;
    }
    void pre_process() {
        pre_preocessed = true;
        ancestors.resize(n);
        int logn{};
        while (n >> logn) logn++;
        for (int i = 0; i < n; i++) {
            ancestors[i] = vi(logn, -1);
        }
        function<void(int, int)> dfs = [&](int v, int p) {
            if (v) ancestors[v][0] = p;
            for (auto &u : adj[v]) {
                if (u != p) dfs(u, v);
            }
        };
        dfs(0, -1);
        for (int i = 1; i < logn; i++) {
            for (int j = 1; j < n; j++) {
                if (ancestors[j][i - 1] == -1) continue;
                ancestors[j][i] = ancestors[ancestors[j][i - 1]][i - 1];
            }
        }
    }
    int kth_ancestor(int v, int k) {
        if (!pre_preocessed) pre_process();
        int curr_node = v;
        int i = 0;
        while (k >> i && curr_node != -1) {
            if ((k >> i) & 1) curr_node = ancestors[curr_node][i];
            i++;
        }
        return curr_node;
    }
};

void solve(int testcase) {
    int n; cin >> n;
    vvi adj(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Tree t(adj);
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
