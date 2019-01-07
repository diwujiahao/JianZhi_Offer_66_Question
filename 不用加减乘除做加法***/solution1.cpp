// 利用二进制 且 和 异或 完成

class Solution {
public:
    int Add(int num1, int num2)
    {
        while (num2 != 0){
            int carry, sum;
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
};
