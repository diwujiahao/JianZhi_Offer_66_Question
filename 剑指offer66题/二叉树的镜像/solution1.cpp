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
public:
    void Mirror(TreeNode *pRoot) {
        // 空节点直接返回
        if (!pRoot){
            return;
        }
        // 交换左右子树链接
        swap(pRoot->left, pRoot->right);
        // 递归
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};