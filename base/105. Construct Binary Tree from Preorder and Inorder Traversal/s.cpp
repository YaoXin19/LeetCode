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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 没有重复值
        if (preorder.size() == 0) return nullptr;
        auto t = std::find(inorder.begin(), inorder.end(), preorder[0]);
        auto left_len = std::distance(inorder.begin(), t);
        auto right_len = std::distance(t+1, inorder.end());
        
        auto left_preorder_begin = ++preorder.begin();
        vector<int> left_preorder(left_preorder_begin, left_preorder_begin+left_len);
        vector<int> right_preorder(left_preorder_begin+left_len, preorder.end());
        
        auto left_inorder_begin = inorder.begin();
        vector<int> left_inorder(left_inorder_begin, left_inorder_begin+left_len);
        vector<int> right_inorder(left_inorder_begin+left_len+1, inorder.end());
        
        TreeNode* root = new TreeNode(*t);
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};