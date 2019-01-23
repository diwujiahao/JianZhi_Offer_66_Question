class Solution {
    vector<int> dp = {0,1,2};
public:
    int rectCover(int number) {
        if (number < 3){
            return number;
        }
        for (int i = 3; i <= number; i++){
            dp.push_back(dp[i-1] + dp[i-2]);
        }
        return dp.back();
    }
};



// 效率低
class Solution {
    vector<int> dp = {0,1,2};
    int recursion(int n){
        if (n < 3){
            return n;
        }
        return recursion(n-1) + recursion(n-2);
    }
public:
    int rectCover(int number) {
        if (number < 3){
            return number;
        }
        return recursion(number);
    }
};



class Solution {
    vector<int> dp = {1,2,-1};
    
public:
    int rectCover(int number) {
        if (number < 3){
            return number;
        }
        int point = 0;
        while(number-- > 2){
            int temp = dp[point] + dp[(point+1)%3];
            point = (point + 2) % 3;
            dp[point] = temp;
            point = (point == 0) ? 2 : point - 1;
        }
        return dp[(point+1)%3];
    }
};
