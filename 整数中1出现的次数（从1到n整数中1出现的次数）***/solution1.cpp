//编程之美上给出的规律：
//
//1. 如果第i位（自右至左，从1开始标号）上的数字为0，则第i位可能出现1的次数由更高位决定（若没有高位，视高位为0），等于更高位数字X当前位数的权重10(i-1)。
//
//2. 如果第i位上的数字为1，则第i位上可能出现1的次数不仅受更高位影响，还受低位影响（若没有低位，视低位为0），等于更高位数字X当前位数的权重10(i-1) +（低位数字+1）。
//
//3. 如果第i位上的数字大于1，则第i位上可能出现1的次数仅由更高位决定（若没有高位，视高位为0），等于（更高位数字+1）X当前位数的权重10(i-1)。

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int result = 0;
        // index 表示位数（0表示个位）
        int index = 0;
        while(n / pow(10, index) > 0){
            int high = n / pow(10, index + 1);
            int current = n % int(pow(10.0, index+1)) / pow(10, index);
            int low = n % int(pow(10.0, index));
            if (current == 0){
                result += high * pow(10, index);
            }
            else if (current == 1){
                result += high * pow(10, index) + low + 1;
            }
            else{
                result += (high+1) * pow(10, index);
            }
            index++;
        }
        return result;
    }
};
