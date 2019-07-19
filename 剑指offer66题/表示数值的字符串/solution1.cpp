class Solution {
    vector<char> num1;
    vector<char> num2;

    // 按e/E拆分为两个数
    bool seperate(char* string){
        // 标记是否出现过e/E
        bool label = false;
        // 遍历 存储
        for (int i = 0; string[i] != '\0'; i++){
            if (string[i] == 'e' || string[i] == 'E'){
                // 出现多个e则有错
                if (label){
                    return false;
                }
                label = true;
                continue;
            }
            if (!label){
                num1.push_back(string[i]);
            }
            else{
                num2.push_back(string[i]);
            }
        }
        // 若出现e，num2不能为空
        if (label && num2.size() == 0){
            return false;
        }
        return true;
    }
    
    // 检查num1是否正确
    bool check_num1(){
        bool point_label = false;
        int point = (num1[0]=='+' || num1[0] == '-') ? 1 : 0;
        while(point < num1.size()){
            if (num1[point] >= '0' && num1[point] <= '9'){
                point++;
                continue;
            }
            if (num1[point] == '.'){
                if (point_label){
                    return false;
                }
                point_label = true;
                point++;
                continue;
            }
            return false;
        }
        return true;
    }
    
    // 检查num2是否正确
    bool check_num2(){
        int point = (num2[0]=='+' || num2[0] == '-') ? 1 : 0;
        while(point < num2.size()){
            if (num2[point] >= '0' && num2[point] <= '9'){
                point++;
                continue;
            }
            return false;
        }
        return true;
    }
    
public:
    bool isNumeric(char* string)
    {
        if (string[0] == '\0'){
            return false;
        }
        if (!seperate(string)){
            return false;
        }
        if (num1.size() > 0 && !check_num1()){
            return false;
        }
        if (num2.size() > 0 && !check_num2()){
            return false;
        }
        return true;
    }
    
};