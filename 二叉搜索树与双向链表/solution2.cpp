/*
 struct TreeNode {
 int val;
 struct TreeNode *left;
 struct TreeNode *right;
 TreeNode(int x) :
 val(x), left(NULL), right(NULL) {
 }
 };*/
class Solution {
    TreeNode* last_node = nullptr;
    TreeNode* result = nullptr;
    void recursion(TreeNode* node){
        if (!node){
            return;
        }
        // 中序递归
        recursion(node->left);
        if (!last_node){
            // 标记最小节点作为结果
            result = node;
        }
        else{
            // 修改指针
            last_node->right = node;
            node->left = last_node;
        }
        // 更新上一个节点
        last_node = node;
        recursion(node->right);
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree){
            return pRootOfTree;
        }
        // 中序遍历
        recursion(pRootOfTree);
        // 返回结果
        return result;
    }
};
