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
    //先序遍历将树转化为序列存入temp
    vector<int> temp;
    void decode(TreeNode *node){
        if (!node){
            temp.push_back(0xFFFFFFFF);
            return;
        }
        temp.push_back(node->val);
        decode(node->left);
        decode(node->right);
    }
    //递归将序列转换为树
    TreeNode* encode(int* &str){
        if (*str == 0xFFFFFFFF){
            str++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(*str);
        str++;
        node->left = encode(str);
        node->right = encode(str);
        return node;
    }
public:
    // 树->序列
    char* Serialize(TreeNode *root) {
        temp.clear();
        decode(root);
        int* result = new int[int(temp.size())];
        for (int i = 0; i < temp.size(); i++){
            result[i] = temp[i];
        }
        return (char*)result;
    }
    // 序列->树
    TreeNode* Deserialize(char *str) {
        int *p=(int*)str;
        return encode(p);
    }
};
