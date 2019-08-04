/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // 前序遍历为“中左右”
        // 可以改为“中右左”,在改为“左右中”,实现后续 
        
        vector<int> res;
        if (!root) return res; 
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            res.push_back(node->val);
            s.pop();
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        
        std::reverse(res.begin(), res.end()); // 中右左 -> 左右中
        return res;
    }
};