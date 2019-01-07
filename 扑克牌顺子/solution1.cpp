class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        // 特殊情况判断
        if (numbers.size() == 0){
            return false;
        }
        sort(numbers.begin(), numbers.end());
        int bingo = 0; // 大小王个数统计
        for (int i = 0; i < numbers.size() - 1; i++){
            // 存储大小王
            if (numbers[i] == 0){
                bingo++;
                continue;
            }
            // 出现重复返回false
            if (numbers[i+1] == numbers[i]){
                return false;
            }
            // 不满足递增 可能使用大小王
            if (numbers[i] != numbers[i+1] - 1){
                bingo = bingo - (numbers[i+1] - numbers[i] -1);
                if (bingo < 0){
                    return false;
                }
            }
        }
        return true;
    }
};