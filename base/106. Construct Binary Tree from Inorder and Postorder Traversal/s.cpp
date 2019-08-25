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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return nullptr;
        auto t = std::find(inorder.begin(), inorder.end(), postorder[postorder.size()-1]);
        
        auto left_len = t - inorder.begin();
        auto right_len = inorder.end() - t + 1;
        
        vector<int> left_inorder(inorder.begin(), inorder.begin()+left_len);
        vector<int> right_inorder(inorder.begin()+left_len+1, inorder.end());

        vector<int> left_postorder(postorder.begin(), postorder.begin()+left_len);
        vector<int> right_postorder(postorder.begin()+left_len, postorder.end()-1);

        TreeNode* root = new TreeNode(*t);
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);
        
        return root;
    }
};