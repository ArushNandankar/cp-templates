#include <bits/stdc++.h>

using namespace std;

template <typename T, typename QueryType = function<T(T, T)>>
class SegmentTree {
public:
    SegmentTree(const vector<T> &input, const QueryType &queryOp) : queryOp(queryOp) {
        n = input.size();
        tree.resize(2 * n);
        for (int i = 0; i < n; ++i)
            tree[n + i] = input[i];
        for (int i = n - 1; i > 0; --i)
            tree[i] = queryOp(tree[i << 1], tree[i << 1 | 1]);
    }
    void update(int idx, T newValue) {
        idx += n;
        tree[idx] = newValue;
        for (idx >>= 1; idx > 0; idx >>= 1)
            tree[idx] = queryOp(tree[idx << 1], tree[idx << 1 | 1]);
    }
    T query(int l, int r) const {
        T result = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                result = queryOp(result, tree[l++]);
            if (r & 1)
                result = queryOp(result, tree[--r]);
        }
        return result;
    }
private:
    int n;
    vector<T> tree;
    QueryType queryOp;
};

int main()
{
    // Example usage with sum query
    vector<int> input = {1, 2, 3, 4, 5};
    SegmentTree<int> segTree(input, [](int a, int b)
                            {
                                return a + b;
                            });
    // Update element at index 2 to 10
    segTree.update(0, 10);
    // Query the sum in the range [1, 4]
    cout << "Sum in the range [1, 4]: " << segTree.query(0, 4) << endl;

    return 0;
}
