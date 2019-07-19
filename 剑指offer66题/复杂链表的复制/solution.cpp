/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
    unordered_map<RandomListNode*, RandomListNode*> hash;
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead){
            return nullptr;
        }
        // 创造头结点
        RandomListNode* root = new RandomListNode(pHead->label);
        RandomListNode* point = root;
        hash[pHead] = root;
        // 遍历节点
        while (pHead){
            // 需要创建next节点
            if (pHead->next){
                // next节点已经存在
                if (hash.find(pHead->next) != hash.end()){
                    point->next = hash[pHead->next];
                }
                else{
                    point->next = new RandomListNode(pHead->next->label);
                    hash[pHead->next] = point->next;
                }
            }
            // 需要创建random节点
            if (pHead->random){
                // random节点已经存在
                if (hash.find(pHead->random) != hash.end()){
                    point->random = hash[pHead->random];
                }
                else{
                    point->random = new RandomListNode(pHead->random->label);
                    hash[pHead->random] = point->random;
                }
            }
            pHead = pHead->next;
            point = point->next;
        }
        return root;
    }
};
