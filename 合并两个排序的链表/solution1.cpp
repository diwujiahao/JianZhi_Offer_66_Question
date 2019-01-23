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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 特殊情况判断
        if (!pHead1){
            return pHead2;
        }
        if (!pHead2){
            return pHead1;
        }
        // 初始化
        ListNode* head = new ListNode(0), *temp = head, *point1 = pHead1, *point2 = pHead2;
        // 开始合并
        while (point1 && point2){
            // point1小
            if (point1->val <= point2->val){
                temp->next = point1;
                point1 = point1->next;
            }
            // point2小
            else{
                temp->next = point2;
                point2 = point2->next;
            }
            temp = temp->next;
        }
        if (point1){
            temp->next = point1;
        }
        if (point2){
            temp->next = point2;
        }
        return head->next;
    }
};