/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* partition(ListNode* begin, ListNode* end){
        ListNode* current = begin;
        ListNode* point = begin->next;
        while (point && point != end){
            if (point->val <= begin->val){
                current = current->next;
                swap(point->val, current->val);
            }
            point = point->next;
        }
        swap(begin->val, current->val);
        return current;
    };
     
    void sort(ListNode* begin, ListNode* end){
        if (!begin || begin == end || !begin->next || begin->next == end){
            return ;
        }
        ListNode* mid = partition(begin, end);
        sort(begin, mid);
        sort(mid->next, end);
    };
     
public:
    ListNode *sortList(ListNode *head) {
        sort(head, nullptr);
        return head;
    }
};