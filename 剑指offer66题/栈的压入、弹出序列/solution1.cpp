class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        vector<bool> label(pushV.size(), false);
        int point_push = -1, point_pop = 0;
        
        // 循环操作
        while(point_push >= 0 || point_pop < popV.size()){
            // 栈空 / 栈顶元素 != 出栈元素 -- 入栈
            if (point_push == -1 || (point_push >= 0 && pushV[point_push] != popV[point_pop])){
                point_push++;
                while(point_push < pushV.size() && label[point_push]){
                    point_push++;
                }
                if (point_push >= pushV.size()){
                    return false;
                }
            }
            // 栈顶元素为出栈元素 -- 出栈
            else{
                label[point_push] = true;
                while(point_push >= 0 && label[point_push]){
                    point_push--;
                }
                point_pop++;
            }
        }
        return true;
    }
};