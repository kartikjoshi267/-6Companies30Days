/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> arr;
    void preorder(TreeNode* root){
        if (root){
            arr.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        preorder(root1);
        preorder(root2);
        sort(arr.begin(), arr.end());
        return arr;
    }
};
