struct bitwise_trie_node {
    bitwise_trie_node *left, *right;
    int cnt{}; // number of elements in the subtree
    bitwise_trie_node() : left(nullptr), right(nullptr) {}
};

struct bitwise_trie {
    bitwise_trie_node *root;
    bitwise_trie() { root = new bitwise_trie_node(); }
    void insert(int x) {
        bitwise_trie_node *cur = root;
        for (int i = 31; i >= 0; i--) {
            if (x & (1 << i)) {
                if (!cur->right) cur->right = new bitwise_trie_node();
                cur = cur->right;
            } else {
                if (!cur->left) cur->left = new bitwise_trie_node();
                cur = cur->left;
            }
            cur->cnt++;
        }
    }
    int search_complement(int x) {
        bitwise_trie_node *cur = root;
        int ans{}; // check this as trie may be empty
        for (int i = 31; i >= 0; i--) {
            if (x & (1 << i)) {
                if (cur->left && cur->left->cnt) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                    ans |= (1 << i);
                }
            } else {
                if (cur->right && cur->right->cnt) {
                    cur = cur->right;
                    ans |= (1 << i);
                } else {
                    cur = cur->left;
                }
            }
        }
        return ans;
    }
};