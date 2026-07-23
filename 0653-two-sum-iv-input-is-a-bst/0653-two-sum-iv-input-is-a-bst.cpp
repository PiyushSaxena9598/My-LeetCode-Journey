class Solution {
public:
    bool searchIterative(TreeNode* root, int target) {
        while (root != NULL) {
            if (root->val == target)
                return true;

            if (target < root->val)
                root = root->left;
            else
                root = root->right;
        }

        return false;
    }

    bool valid(TreeNode* root, TreeNode* original, int k) {
        if (root == NULL)
            return false;

        int val = k - root->val;
        if (val != root->val && searchIterative(original, val))
            return true;

        return valid(root->left, original, k) ||
               valid(root->right, original, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return valid(root, root, k);
    }
};