/**
 *  struct ListNode {
 *        int val;
 *        struct ListNode *next;
 *        ListNode(int x) :
 *              val(x), next(NULL) {
 *        }
 *  };
 */

// 递归实现

class Solution {
    vector<int> result;
    void recursion(ListNode* node){
        if (node->next){
            recursion(node->next);
        }
        result.push_back(node->val);
    }
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head){
            recursion(head);
        }
        return result;
    }
};
