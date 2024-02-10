// for everynode in the MST we will store a vector which will
// keep the elements in the range in sorted order
class Merge_Sort_Tree {
private:
    vi A;
    vvi tree;
    int n;
    void build(int i, int l, int r) {
        if (l == r) {
            tree[i].push_back(A[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        merge(all(tree[2 * i]), all(tree[2 * i + 1]), back_inserter(tree[i]));
    }
    int _query(int i, int l, int r, int x, int y, int K) {
        if (l > y || r < x) {
            return 0;
        }
        if (x <= l && r <= y) {
            auto it = lower_bound(all(tree[i]), K);
            return distance(tree[i].begin(), it);
        }
        int mid = l + (r - l) / 2;
        return _query(2 * i, l, mid, x, y, K) + _query(2 * i + 1, mid + 1, r, x, y, K);
    }
public:
    Merge_Sort_Tree(vi &a) {
        A = a;
        n = A.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
    int query(int l, int r, int K) {
        return _query(1, 0, n - 1, l, r, K);
    }
};
