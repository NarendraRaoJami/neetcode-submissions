class Trie {
public:
    Trie* links[26];
    bool flag;

    Trie() {
        flag = false;
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Trie* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Trie* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
private:
    Trie* root;

    bool dfs(Trie* node, string &word, int index) {
        if (index == word.size())
            return node->isEnd();

        char ch = word[index];

        if (ch != '.') {
            if (!node->containsKey(ch))
                return false;
            return dfs(node->get(ch), word, index + 1);
        }

        // '.' can match any character
        for (int i = 0; i < 26; i++) {
            if (node->links[i] != nullptr) {
                if (dfs(node->links[i], word, index + 1))
                    return true;
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        Trie* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                node->put(ch, new Trie());

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};