// 中序遍历二叉搜索树得到一个升序序列
class Solution {
    int count = 0;
    TreeNode *result = nullptr;
    void traversal(TreeNode* node, int k){
        if (!node){
            return;
        }
        // 中序遍历
        traversal(node->left,k);
        count++;
        if (count == k){
            result = node;
            return;
        }
        traversal(node->right,k);
    }
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        traversal(pRoot,k);
        return result;
    }
};