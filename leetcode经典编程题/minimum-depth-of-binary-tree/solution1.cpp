class Solution {
    int recursion(TreeNode *node){
        if (!node->left && !node->right){
            return 1;
        }
        int left_depth = (node->left) ? recursion(node->left) : INT_MAX;
        int right_depth = (node->right) ? recursion(node->right) : INT_MAX;
        return min(left_depth, right_depth) + 1;
    }
public:
    int run(TreeNode *root) {
        return (root) ? recursion(root) : 0;
    }
};