#include <bits/stdc++.h>

using namespace std;

template <typename T, typename QueryType = function<T(T, T)>>
class SparseTable
{
private:
    vector<vector<T>> table;
    vector<int> log;
    int n;
    QueryType queryOp;

public:
    SparseTable(const vector<T> &input, const QueryType &queryOp) : queryOp(queryOp) // O(nlogn)
    {
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
    T query(int l, int r)
    {
        assert(l <= r);
        assert(l >= 0);
        assert(r < n);
        int j = log[r - l + 1];
        return queryOp(table[l][j], table[r - (1 << j) + 1][j]);
    }
};

int main()
{
    SparseTable<int> sparseTable({2, 2, 4, 4, 8}, [](int a, int b)
                                 { return min(a, b); });
    cout << sparseTable.query(0, 4) << endl;
    return 0;
}