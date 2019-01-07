class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.size() == 0){
            return "";
        }
        string left, right;
        left = str.substr(0,n);
        right = str.substr(n);
        return right + left;
    }
};