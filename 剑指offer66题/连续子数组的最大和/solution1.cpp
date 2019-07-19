// 动态规划
// dp数组中，dp[i]表示以i为结尾的最大子串和

class Solution {
    vector<int> dp;
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int result = INT_MIN;
        dp = vector<int>(array.size(), 0);
        dp[0] = array[0];
        for (int i = 1; i < array.size(); i++){
            if (dp[i-1] < 0){
                dp[i] = array[i];
            }
            else{
                dp[i] = dp[i-1] + array[i];
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
