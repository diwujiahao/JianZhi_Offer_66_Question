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
    // 判断当前节点是否重合
    bool subTree(TreeNode* node1, TreeNode* node2){
        // node2为空
        if (!node2){
            return true;
        }
        // node1为空，node2非空
        if (!node1){
            return false;
        }
        // 均不为空
        if (node1->val != node2->val){
            return false;
        }
        // 节点值相同
        return subTree(node1->left, node2->left) && subTree(node1->right, node2->right);
        
    }
    // 递归查看是否已当前节点为子树
    bool recursion(TreeNode* node1, TreeNode* node2){
        if (!node1){
            return false;
        }
        if (subTree(node1, node2)){
            return true;
        }
        if (recursion(node1->left, node2)){
            return true;
        }
        if (recursion(node1->right, node2)){
            return true;
        }
        return false;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        // 空树
        if (!pRoot2){
            return false;
        }
        return recursion(pRoot1, pRoot2);
    }
};



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
    // 判断当前节点是否重合
    bool subTree(TreeNode* node1, TreeNode* node2){
        // node2为空
        if (!node2){
            return true;
        }
        // node1为空，node2非空
        if (!node1){
            return false;
        }
        // 均不为空
        if (node1->val != node2->val){
            return false;
        }
        // 节点值相同
        return subTree(node1->left, node2->left) && subTree(node1->right, node2->right);
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        // 空树
        if (!pRoot1 || !pRoot2){
            return false;
        }
        return subTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};
