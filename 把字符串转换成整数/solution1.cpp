class Solution {
    
public:
    int StrToInt(string str) {
        int point = 0; // 扫描指针
        int p_o_n = 1; // 正负号标记
        long long num = 0; // 数字标记
        // 处理正负号
        if (str[0] == '+'){
            point++;
        }
        else if (str[0] == '-'){
            point++;
            p_o_n = -1;
        }
        // 处理数字
        while (point < str.size()){
            if (str[point] >= '0' && str[point] <= '9'){
                num = num * 10 + (str[point] - '0');
                point++;
            }
            else{
                return 0;
            }
        }
        // 返回
        return int(num * p_o_n); 
    }
};