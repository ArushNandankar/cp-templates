class DSU {
private:
    int n;
    vi rank, parent;
    void makeSet() {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
public:
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        this->n = n;
        makeSet();
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y) {
        int xset = find(x);
        int yset = find(y);
        if (xset == yset)
            return;
        else if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};