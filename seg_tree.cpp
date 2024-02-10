#include <bits/stdc++.h>

using namespace std;

// Range _update and Range Sum
class seg_tree
{
private:
    int n;
    vector<int> tree, lazy;
    void _build(int node, int start, int end, vector<int> &a)
    {
        if (start == end)
        {
            tree[node] = a[start];
        }
        else
        {
            int mid = (start + end) / 2;
            _build(2 * node, start, mid, a);
            _build(2 * node + 1, mid + 1, end, a);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void _update(int node, int start, int end, int l, int r, int val)
    {
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > r || end < l)
        {
            return;
        }
        if (start >= l && end <= r)
        {
            tree[node] += (end - start + 1) * val;
            if (start != end)
            {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        _update(2 * node, start, mid, l, r, val);
        _update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int _query(int node, int start, int end, int l, int r)
    {
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > r || end < l)
        {
            return 0;
        }
        if (start >= l && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left = _query(2 * node, start, mid, l, r);
        int right = _query(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }

public:
    seg_tree(vector<int> &a)
    {
        n = a.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        _build(1, 0, n - 1, a);
    }
    int query(int l, int r)
    {
        assert(l <= r);
        assert(l >= 0 && r < n);
        return _query(1, 0, n - 1, l, r);
    }
    void update(int l, int r, int val)
    {
        assert(l <= r);
        assert(l >= 0 && r < n);
        _update(1, 0, n - 1, l, r, val);
    }
};

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    seg_tree tree(a);
    tree.update(0, 4, 1);
    cout << tree.query(0, 0) << endl;
    cout << tree.query(1, 1) << endl;
    cout << tree.query(2, 2) << endl;
    cout << tree.query(3, 3) << endl;
    cout << tree.query(4, 4) << endl;
    cout << tree.query(0, 4) << endl;
    return 0;
}
