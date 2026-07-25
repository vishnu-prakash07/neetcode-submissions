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
public:
    int count = 0;

    void checkGood(TreeNode* root,int pathMax){
        if (!root)
            return;
        if (root->val >= pathMax){
            count++;
            pathMax = root->val;
        }
        checkGood(root->left,pathMax);
        checkGood(root->right,pathMax);
    }

    int goodNodes(TreeNode* root) {
        checkGood(root,-101);
        return count;
    }
};
