class Solution {
    vector<bool> label; // 标记字符是否使用过
    vector<string> result; // 存储结果
    void recursion(string str, string temp){
        // 如果temp填充完成 添加结果并返回
        if (temp.size() == label.size()){
            result.push_back(temp);
            return;
        }
        // 遍历没有使用过的字符
        for (int i = 0; i < str.size(); i++){
            // 第i个字符没有使用过
            if (!label[i]){
                // 如果当前字符与上一个相同且上一个没有使用，这个也跳过，避免重复
                if (i-1 >= 0 && !label[i-1] && str[i-1] == str[i]){
                    continue;
                }
                // 递归
                label[i] = true;
                temp += str[i];
                recursion(str, temp);
                label[i] = false;
                temp.erase(temp.begin() + temp.size() - 1);
            }
        }
    }
public:
    vector<string> Permutation(string str) {
        if (str.size() == 0){
            return result;
        }
        label = vector<bool>(str.size(), false);
        recursion(str, "");
        return result;
    }
};