// 排序后的中位数即为目标（如果目标存在）

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        // 统计中位数出现个数
        int count = 1;
        int point = int(numbers.size()) / 2;
        while(numbers[point] == numbers[point-1]){
            count++;
            point--;
        }
        point = int(numbers.size()) / 2;
        while(numbers[point] == numbers[point+1]){
            count++;
            point++;
        }
        // 判断返回结果
        return (count > numbers.size()/2) ? numbers[numbers.size()/2] : 0 ;
    }
};
