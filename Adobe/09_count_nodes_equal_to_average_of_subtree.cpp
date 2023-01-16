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
    multimap<int,int> m;
    int numOfNodes(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        return (1 + numOfNodes(root->left) + numOfNodes(root->right));
    }

    int sumSubtree(TreeNode* root){
        if (!root){
            return 0;
        }

        return (root->val) + sumSubtree(root->left) + sumSubtree(root->right);
    }

    void dfs(TreeNode* root){
        if (root == NULL){
            return;
        }

        m.insert({root->val, sumSubtree(root)/numOfNodes(root)});
        dfs(root->left);
        dfs(root->right);
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        int cnt = 0;
        for (auto &i : m){
            if (i.first == i.second)
                cnt++;
        }
        return cnt;
    }
};
