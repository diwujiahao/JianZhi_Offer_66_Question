//前序遍历{1,2,4,7,3,5,6,8}
//中序遍历{4,7,2,1,5,3,8,6}

class Solution {
    
    // 寻找中序遍历的根节点索引 mid
    int find_mid(vector<int> vin, int vin_begin, int vin_end, int target){
        for (int i = vin_begin; i <= vin_end; i++){
            if (vin[i] == target){
                return i;
            }
        }
        return -1;
    }
    
    // 建立当前节点并返回
    TreeNode* build(vector<int> pre, int pre_begin, int pre_end, vector<int> vin, int vin_begin, int vin_end){
        // 越界情况，返回叶子节点的左右子树
        if (pre_begin > pre_end || vin_begin > vin_end){
            return nullptr;
        }
        // 建立当前节点
        TreeNode *node = new TreeNode(pre[pre_begin]);
        // 寻找中序遍历的根节点索引 mid
        int mid = find_mid(vin, vin_begin, vin_end, pre[pre_begin]);
        // 递归建立左右子树
        node->left = build(pre, pre_begin+1, pre_begin+mid-vin_begin, vin, vin_begin, mid-1);
        node->right = build(pre, pre_begin+mid-vin_begin+1, pre_end, vin, mid+1, vin_end);
        return node;
    }
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode *root = build(pre, 0, int(pre.size())-1, vin, 0, int(vin.size())-1);
        return root;
    }
};
