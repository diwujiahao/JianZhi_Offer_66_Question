/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 双指针寻找倒数第k个节点

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *current = pListHead, *k_next = pListHead;
        while(k--){
            if (!k_next){
                return nullptr;
            }
            k_next = k_next->next;
        }
        while(k_next){
            current = current->next;
            k_next = k_next->next;
        }
        return current;
    }
};