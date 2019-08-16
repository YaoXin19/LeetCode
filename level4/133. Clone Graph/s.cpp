/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        int v = node->val;
        dfs(node);
        for (const auto& item : value_oldnode_map) {
            for (const auto& node_ptr : value_oldnode_map[item.first])    
                value_newnode_map[item.first]->neighbors.push_back(value_newnode_map[node_ptr->val]); 
        }
        return value_newnode_map[v];
    }

private:
    void dfs(Node* node) {
        if (value_oldnode_map.find(node->val) != value_oldnode_map.end())
            return;
        value_oldnode_map.emplace(node->val, node->neighbors);
        Node* new_node = new Node();
        new_node->val = node->val;
        value_newnode_map.emplace(node->val, new_node);
        for (Node* neighbor : node->neighbors)
            dfs(neighbor);
    }

private:
    std::unordered_map<int, vector<Node*>> value_oldnode_map; // 通过val指来找到邻居的val值
    std::unordered_map<int, Node*> value_newnode_map; // 通过val找到新生成的node
};