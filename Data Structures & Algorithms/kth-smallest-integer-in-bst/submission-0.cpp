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

    void inorder(TreeNode* root,vector<int>& nodes){
        if (root){
            inorder(root->left,nodes);
            nodes.push_back(root->val);
            inorder(root->right,nodes);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        inorder(root,nodes);
        for (auto &it:nodes)
            cout << it << " ";
        int ans;
        int index = 0;
        while(k){
            k--;
            ans = nodes[index++];
        }
        return ans;
    }
};
