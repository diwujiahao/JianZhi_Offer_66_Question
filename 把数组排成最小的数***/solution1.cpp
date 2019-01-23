class Solution {
    // 若 num1-num2 > num2-num1 则 num2 应放在 num1 前
    bool compare(int num1, int num2){
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string r1 = s1 + s2;
        string r2 = s2 + s1;
        return r1 <= r2;
    }
public:
    string PrintMinNumber(vector<int> numbers) {
        // 冒泡排序
        for (int i = 0; i < numbers.size(); i++){
            for (int j = 0; j < numbers.size() - i - 1; j++){
                // j-1 和 j 是逆序
                if (!compare(numbers[j], numbers[j+1])){
                    swap(numbers[j], numbers[j+1]);
                }
            }
        }
        string result = "";
        for (int i = 0; i < numbers.size(); i++){
            result += to_string(numbers[i]);
        }
        return result;
    }
};
