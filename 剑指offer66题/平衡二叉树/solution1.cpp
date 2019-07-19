class Solution {
    // 返回 node 节点下的最深深度
    int recursion(TreeNode* node, int depth){
        if (!node){
            return depth;
        }
        // 获取左右子树深度
        int left = recursion(node->left, depth + 1);
        int right = recursion(node->right, depth + 1);
        // 判断是否打破平衡条件
        if (abs(left-right) > 1 || left == -1 || right == -1){
            return -1;
        }
        // 返回当前节点深度
        return max(left, right);
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return (recursion(pRoot, 1) == -1) ? false : true ;
    }
};