// 递推公式

class Solution {

public:
    int LastRemaining_Solution(int n, int m)
    {
        
        vector<int> data(n, 0);
        for (int i = 1; i < n; i++){
            data[i] = (data[i-1] + m) % (i+1);
        }
        return (data.size() > 0) ? data[n-1] : -1;
    }
};
