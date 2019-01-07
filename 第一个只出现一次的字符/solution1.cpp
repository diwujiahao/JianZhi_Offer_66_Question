class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> hash;
        for (int i = 0; i < str.size(); i++){
            // 如果出现过 +1
            if (hash.find(str[i]) != hash.end()){
                hash[str[i]]++;
            }
            // 如果没出现过 插入
            else{
                hash[str[i]] = 1;
            }
        }

        for (int i = 0; i < str.size(); i++){
            if (hash[str[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};