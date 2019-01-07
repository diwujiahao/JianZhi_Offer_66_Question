class Solution {
public:
    string ReverseSentence(string str) {
        // temp 存储当前单词
        // result 存储返回结果
        string temp = "", result = "";
        for (int i = 0;  i < str.size(); i++){
            if (str[i] == ' '){
                result = " " + temp + result;
                temp = "";
            }
            else{
                temp += str[i];
            }
        }
        result = temp + result;
        return result;
    }
};
