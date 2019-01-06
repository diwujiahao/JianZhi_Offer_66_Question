/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

// unordered_map 与 map
// unordered_map：哈希表，空间复杂度高，查询效率O(1)
// map：红黑树，支持顺序查找，查询效率O(logN)


class Solution {
    unordered_map<ListNode*, bool> map;
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        // 遍历链表
        while(pHead){
            // 若当前节点出现过 即出现循环
            if (map.find(pHead) != map.end()){
                return pHead;
            }
            // 正常遍历
            else{
                // 存储当前节点
                map[pHead] = true;
                // 下一个
                pHead = pHead->next;
            }
        }
        return nullptr;
    }
};
