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
    unordered_map<Node*, Node*>vis;
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        if(vis.find(node) != vis.end()){
            return vis[node];
        }
        Node* root = new Node(node -> val);
        vis[node] = root;
        for(Node* nbr: node->neighbors){
            root->neighbors.push_back(cloneGraph(nbr));
        }
        return root;
    }
};