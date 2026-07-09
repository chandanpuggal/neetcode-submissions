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
    // LeetCode: https://leetcode.com/problems/same-tree/?envType=problem-list-v2&envId=5zd3o9vd
    // Video: https://www.youtube.com/watch?v=vRbbcKXCxOw

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == NULL) && (q == NULL))
            return true;

        if ((p == NULL) && (q != NULL))
            return false;

        if ((p != NULL) && (q == NULL))
            return false;
        
        if (p->val != q->val)
            return false;
        
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        
        return left && right;
    }
};
