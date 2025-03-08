#include <bits/stdc++.h>
using namespace std;

/* Trie Template */
const int ALPHABET_SIZE = 26;
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}
class Trie {
private:
    struct TrieNode *root;
public:
    Trie() {
        root = getNode();
    }
    void insert(string key) {
        struct TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }
    bool search(string key) const {
        struct TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl->isEndOfWord);
    }
};
/* Trie Template END */

int main()
{
    Trie t;
    t.insert("Hello");
    cout << t.search("Hello") << " " << t.search("World") << "\n";
    return 0;
}