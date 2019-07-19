/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead){
            return pHead;
        }
        ListNode* current = pHead, *next = pHead->next;
        pHead->next = nullptr;
        while (next){
            ListNode* next_next = next->next;
            next->next = current;
            current = next;
            next = next_next;
        }
        return current;
    }
};