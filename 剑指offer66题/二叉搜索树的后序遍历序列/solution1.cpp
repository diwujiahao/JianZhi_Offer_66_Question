class Solution {
    // 递归检测是否为后序遍历
    bool check(vector<int> sequence, int begin, int end){
        // 指针交叉，返回true
        if (begin >= end){
            return true;
        }
        // 取根节点
        int target = sequence[end--];
        // 从前向后找到左右子树分界点 （point-1，point）
        // 并检查是否前小后大
        int point = begin;
        while(sequence[point] < target){
            point++;
        }
        for (int i = point; i <= end; i++){
            if (sequence[i] <= target){
                return false;
            }
            point++;
        }
        // 递归检查
        return check(sequence, begin, point-1) && check(sequence, point, end);
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return (sequence.size() == 0) ? false : check(sequence, 0, int(sequence.size()) - 1);
    }
};