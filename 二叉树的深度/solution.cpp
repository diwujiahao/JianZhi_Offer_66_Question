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
    int get_depth(TreeNode* node, int depth){
        if (!node){
            return depth;
        }
        int left = get_depth(node->left, depth+1);
        int right = get_depth(node->right, depth+1);
        return max(left, right);
    }
public:
    int TreeDepth(TreeNode* pRoot)
    {
        return get_depth(pRoot, 0);
    }
};