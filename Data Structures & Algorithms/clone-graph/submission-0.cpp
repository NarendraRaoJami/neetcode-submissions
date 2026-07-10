/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        unordered_map<Node*,Node*> hash_map;
        Node* root = new Node(node->val);
        hash_map[node] = root;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* new_node = q.front();
            q.pop();
            for(Node* neigh : new_node->neighbors){
                if(hash_map.find(neigh) == hash_map.end()){
                    hash_map[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                hash_map[new_node]->neighbors.push_back(hash_map[neigh]);
            }
        }
        return hash_map[node];
    }
};
