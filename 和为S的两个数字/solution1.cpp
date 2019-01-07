// 和相同的两个数a和b， min(a,b)小的乘积小

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result; // 结果存储
        int point_left = 0, point_right = array.size() - 1; // 指针声明
        while(point_left < array.size()){
            // 若当前求和大于sum，移动右指针
            if (array[point_left] + array[point_right] > sum){
                point_right--;
            }
            // 若当前求和小于sum，移动左指针
            else if (array[point_left] + array[point_right] < sum){
                point_left++;
                point_right = array.size() - 1;
            }
            // 否则找到答案
            else{
                result.push_back(array[point_left]);
                result.push_back(array[point_right]);
                return result;
            }
        }
        return result;
    }
};
