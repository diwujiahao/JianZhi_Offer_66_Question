class Solution {
    bool label;
public:
    double Power(double base, int exponent) {
        // 基数为0
        if (base == 0){
            return 0;
        }
        // 判定指数正负号
        label = (exponent >= 0) ? true : false ;
        exponent = abs(exponent);
        // 开始计算
        double result = 1;
        double multiplier = base;
        while (exponent > 0){
            if ((exponent & 1) == 1){
                result *= multiplier;
            }
            multiplier *= multiplier;
            exponent >>= 1;
            
        }
        return (label)? result : 1/result;
    }
};
