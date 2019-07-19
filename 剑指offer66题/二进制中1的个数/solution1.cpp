class Solution {
    
public:
    int  NumberOf1(int n) {
        if (n == INT_MIN){
            return 1;
        }
        // 正负号标记
        int label = (n < 0) ? false : true;
        n = abs(n);
        // 统计源码数据
        int one = 0, back_zero = 0;
        bool back_zero_label = true;
        while (n > 0){
            if ((n & 1) == 1){
                one++;
                back_zero_label = false;
            }
            else if (back_zero_label){
                back_zero++;
            }
            n >>= 1;
        }
        // 返回结果
        return (label) ? one : 32 - one - back_zero + 1;
    }
};