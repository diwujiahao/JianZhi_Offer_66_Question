/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
    // 判断当前节点为左节点/右节点
    // 左1 右2 根节点0
    int left_or_right(TreeLinkNode* node){
        // 父节点不存在
        if (!node->next){
            return 0;
        }
        // pNode是左节点
        if (node == node->next->left){
            return 1;
        }
        // pNode是右节点
        else if (node == node->next->right){
            return 2;
        }
        //不存在情况
        else{
            return -1;
        }
    }
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // 右节点不为空--寻找右节点的最左叶节点
        if (pNode->right){
            TreeLinkNode* point = pNode->right;
            while(point->left){
                point = point->left;
            }
            return point;
        }
        // 右节点为空--寻找第一个不是右节点的父节点
        else{
            TreeLinkNode* point = pNode;
            while(left_or_right(point) == 2){
                point = point->next;
            }
            if (left_or_right(point) == 0){
                return nullptr;
            }
            else{
                return point->next;
            }
        }
    }
};
