/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
    // 删除从point开始的连续重复数字
    // point 指向第一个重复数字
    // last_point 指向point的上一个节点（若point为头结点，则last_point为空）
    // temp 指向第一个不重复的节点（即将与last_point拼接的节点）
    ListNode* delete_node(ListNode* point, ListNode* last_point){
        // 临时指针指向第一个非重复数字
        ListNode* temp = point; // 临时指针
        while (temp->next && temp->val == temp->next->val){
            temp = temp->next;
        }
        temp = temp->next;
        // 删除本段重复数字
        point = temp;
        if (last_point){
            last_point->next = point;
        }
        return point;
    }
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* point = pHead;
        ListNode* last_point = nullptr;
        while (point && point->next){
            // 如果从point出现重复
            if (point->val == point->next->val){
                point = delete_node(point, last_point);
                // 若重复从头结点开始，更新头结点。
                if (!last_point){
                    pHead = point;
                }
            }
            // point节点未出现重复
            else{
                last_point = point;
                point = point->next;
            }
        }
        return pHead;
    }
};