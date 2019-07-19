class Solution {
    stack<int> data;
    int operate(int num_l, int num_r, string label){
        if (label == "+")
            return num_l + num_r;
        else if (label == "-")
            return num_l - num_r;
        else if (label == "*")
            return num_l * num_r;
        else if (label == "/")
            return num_l / num_r;
        return -1;
    };
    
public:
    int evalRPN(vector<string> &tokens) {
        for (string i : tokens){
            // 遇到操作符->进行运算
            if (i == "+" || i == "-" || i == "*" || i == "/"){
                int num_r = data.top();    data.pop();
                int num_l = data.top();    data.pop();
                data.push(operate(num_l, num_r, i));
            }
            // 遇到数字->保存数字
            else{
                data.push(stoi(i));
            }
        }
        return data.top();
    }
};