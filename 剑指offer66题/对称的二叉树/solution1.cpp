/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

class Solution {
    bool recursion(TreeNode* node1, TreeNode* node2){
        // 两个节点均为空
        if (!node1 && !node2){
            return true;
        }
        // 某一个为空 另一个不为空
        if (!(node1 && node2)){
            return false;
        }
        // 两个节点均非空
        if (node1->val != node2->val){
            return false;
        }
        
        // 递归调用
        if (!recursion(node1->left, node2->right)){
            return false;
        }
        if (!recursion(node1->right, node2->left)){
            return false;
        }
        return true;
    }
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (! pRoot){
            return true;
        }
        return recursion(pRoot->left, pRoot->right);
    }
    
};
