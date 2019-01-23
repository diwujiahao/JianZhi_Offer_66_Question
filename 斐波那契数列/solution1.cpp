class Solution {
    vector<int> data = {0,1};
public:
    int Fibonacci(int n) {
        // 特殊情况判断
        if (n < 2){
            return n;
        }
        // 循环计算
        while (n-- > 1){
            data.push_back(data[data.size()-1] + data[data.size()-2]);
        }
        return data.back();
    }
};



class Solution {
public:
    int Fibonacci(int n) {
        int data1 = 0, data2 = 1;
        while (n--){
            // data2前进一个数字
            data2 = data1 + data2;
            // data1前进一个数字
            data1 = data2 - data1;
        }
        return data1;
    }
};
