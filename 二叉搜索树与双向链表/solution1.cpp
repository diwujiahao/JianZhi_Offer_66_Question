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
    vector<TreeNode*> data;
    void recursion(TreeNode* node){
        if (!node){
            return;
        }
        recursion(node->left);
        data.push_back(node);
        recursion(node->right);
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree){
            return pRootOfTree;
        }
        // 中序遍历得到有序队列
        recursion(pRootOfTree);
        // 修改连边
        data[0]->left = nullptr;
        for (int i = 1; i < data.size(); i++){
            data[i-1]->right = data[i];
            data[i]->left = data[i-1];
        }
        data[data.size()-1]->right = nullptr;
        // 返回结果
        return data[0];
    }
};