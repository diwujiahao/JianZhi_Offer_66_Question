class Solution {
    TreeNode* root;
    int pre_index;
    
    int find_mid(vector<int> vin, int vin_begin, int vin_end, int target){
        for (int i = vin_begin; i <= vin_end; i++){
            if (vin[i] == target){
                return i;
            }
        }
        return -1;
    }
    
    // left == false; right == true;
    void build(TreeNode* node, bool l_o_r, vector<int> pre, vector<int> vin, int vin_begin, int vin_end){
        if (pre_index >= pre.size()){
            return;
        }
        // 建立左子树
        if (!l_o_r){
            node->left = new TreeNode(pre[pre_index]);
            node = node->left;
        }
        // 建立右子树
        else{
            node->right = new TreeNode(pre[pre_index]);
            node = node->right;
        }
        
        // 在中序中找到当前节点index
        int mid = find_mid(vin, vin_begin, vin_end, pre[pre_index]);
        
        pre_index++;
        // 递归建左子树
        if (mid > vin_begin){
            build(node, false, pre, vin, vin_begin, mid - 1);
        }
        // 递归建u右子树
        if (mid < vin_end){
            build(node, true, pre, vin, mid + 1, vin_end);
        }
    }
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        pre_index = 0; // 更新index
        if (pre.size() == 0){
            return root;
        }
        // 建立根节点
        root = new TreeNode(pre[pre_index]);
        int mid = find_mid(vin, 0, int(vin.size())-1, pre[pre_index]);
        pre_index++;
        // 递归建左子树
        if (mid > 0){
            build(root, false, pre, vin, 0, mid - 1);
        }
        // 递归建右子树
        if (mid < vin.size() - 1){
            build(root, true, pre, vin, mid + 1, int(vin.size())-1);
        }
        // 返回结果
        return root;
    }
};
