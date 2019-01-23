class Solution {
    vector<int> dp = {0,1,2};
public:
    int jumpFloor(int number) {
        // 特殊情况判断
        if (number < 3){
            return number;
        }
        // 动态规划
        for (int i = 3; i <= number; i++){
            dp.push_back(dp[i-1] + dp[i-2]);
        }
        return dp.back();
    }
};



class Solution {
    vector<int> dp = {1,2};
public:
    int jumpFloor(int number) {
        // 特殊情况判断
        if (number < 3){
            return number;
        }
        // 动态规划
        while (number-- > 2){
            dp[1] = dp[0] + dp[1];
            dp[0] = dp[1] - dp[0];
        }
        return dp[1];
    }
};
