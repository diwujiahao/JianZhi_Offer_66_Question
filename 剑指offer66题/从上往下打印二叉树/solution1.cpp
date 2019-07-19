/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 层次遍历
// 利用队列实现

class Solution {
    queue<TreeNode*> data;
    vector<int> result;
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        // 特殊情况判断
        if (!root){
            return result;
        }
        // 初始化
        data.push(root);
        while(!data.empty()){
            // 取出一个节点
            TreeNode* temp = data.front();
            data.pop();
            // 更新结果
            result.push_back(temp->val);
            // 放入新节点
            if (temp->left){
                data.push(temp->left);
            }
            if (temp->right){
                data.push(temp->right);
            }
        }
        return result;
    }
};