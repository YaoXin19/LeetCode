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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            std::vector<int> v;
            while (size--) {
                root = q.front();
                v.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
                q.pop();               
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};