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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unordered_map<ListNode*, int> hash;
        ListNode *point = pHead1;
        // 第一个链表存入哈希表
        while(point){
            hash[point] = 1;
            point = point->next;
        }
        // 查看第二个链表中第一个出现过的节点
        point = pHead2;
        while(point){
            if (hash.find(point) != hash.end()){
                return point;
            }
            point = point->next;
        }
        return nullptr;
    }
};