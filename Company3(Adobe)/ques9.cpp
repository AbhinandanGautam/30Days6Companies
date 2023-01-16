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
    int cnt;

    vector<int> traverse(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }

        vector<int> l = traverse(root->left);
        vector<int> r = traverse(root->right);
        
        int l_sum = l[0];
        int r_sum = r[0];

        int count = 1 + l[1] + r[1];
        int sum = root->val + l_sum + r_sum;

        int avg = sum/count;

        if(root->val == avg){
            cnt++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        cnt = 0;
        traverse(root);
        return cnt;
    }
};