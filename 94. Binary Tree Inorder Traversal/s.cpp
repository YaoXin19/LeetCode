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
    
    void goAlongLeftSide(TreeNode* root, stack<TreeNode*>* s) {
        while(root) {
            s->push(root);
            root = root->left;
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> v;
        stack<TreeNode*> s;
        
        while(true) {
            this->goAlongLeftSide(root, &s); // 延左子树一直压栈到底
            if (s.empty()) break;
            root = s.top(); // 弹出并访问
            v.push_back(root->val);
            root = root->right; // 右子树
            s.pop();
        }

        return v;
    }
};