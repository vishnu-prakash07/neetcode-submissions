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

bool checkValid(TreeNode* root,long long low,long long high){
    if (!root)
        return true;
    if (root->val <= low || root->val >= high)
        return false;
    return (checkValid(root->left,low,root->val) && checkValid(root->right,root->val,high));
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return checkValid(root,LLONG_MIN,LLONG_MAX);
    }
};
