// 借助char*递归

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        //str匹配完成
        if (str[0] == '\0'){
            if (pattern[0] == '\0'){
                return true;
            }
            else if (pattern[1] == '*'){
                return match(str, pattern+2);
            }
            else{
                return false;
            }
        }
        // pattern匹配完成
        if (pattern[0] == '\0'){
            return false;
        }
        // 下一位出现*
        if (pattern[1] == '*'){
            if (pattern[0] == str[0] || pattern[0] == '.'){
                return match(str+1, pattern) || match(str, pattern+2);
            }
            else{
                return match(str, pattern+2);
            }
        }
        // 没有出现*
        else{
            if (pattern[0] == str[0] || pattern[0] == '.'){
                return match(str+1, pattern+1);
            }
        }
        return false;
    }
};