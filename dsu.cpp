class DSU {
private:
    vi parent;
    vi siz;
    void make_set(int v) {
        parent[v] = v; siz[v] = 1;
    }
public:
    DSU (int n) {
        parent.resize(n);
        siz.resize(n);
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    }
    int find_set(int v) {
        return (v == parent[v]) ? v : parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return;
        if(siz[a] < siz[b]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b]; 
        siz[b] = 0; 
    }
    int get_size(int v){
        return siz[find_set(v)];
    }
};
