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
    vector<vector<int>> result;
    void recursion(TreeNode* node, int layer){
        if (!node){
            return;
        }
        // result中没有当前层次，加入当前节点
        if (layer >= result.size()){
            result.push_back(vector<int>(1, node->val));
        }
        // result中含有当前层次，直接加入
        else{
            result[layer].push_back(node->val);
        }
        // 递归调用
        recursion(node->left, layer+1);
        recursion(node->right, layer+1);
    }
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            recursion(pRoot, 0);
            return result;
        }
};
