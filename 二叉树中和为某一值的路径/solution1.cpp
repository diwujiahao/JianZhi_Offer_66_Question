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
    vector<vector<int>> result;
    // 深度优先搜索
    void recursion(TreeNode* node, vector<int> temp, int target){
        // 加入当前节点
        temp.push_back(node->val);
        target -= node->val;
        // 判断是否完成目标
        if (!node->left && !node->right && target == 0){
            result.push_back(temp);
            return;
        }
        // 递归
        if (node->left){
            recursion(node->left, temp, target);
        }
        if (node->right){
            recursion(node->right, temp, target);
        }
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root){
            recursion(root, vector<int>(0), expectNumber);
        }
        return result;
    }
};
