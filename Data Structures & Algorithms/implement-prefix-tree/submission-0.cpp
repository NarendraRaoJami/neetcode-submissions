struct Trie {
    Trie* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    Trie* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch,Trie* trie){
        links[ch - 'a'] = trie;
    }

    bool isend(){
        return flag;
    }

    void setend(){
        flag = true;
    }
};

class PrefixTree {
    Trie* root;
public:
    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        Trie* node = root;
        for(int i = 0;i < word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Trie());
            }
            node = node->get(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
        Trie* node = root;
        for(int i = 0;i < word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            else{
                node = node->get(word[i]);
            }
        }
        return node->isend();
    }
    
    bool startsWith(string prefix) {
        Trie* node = root;
        for(int i = 0;i < prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
