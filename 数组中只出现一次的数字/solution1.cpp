class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        set<int> hash;
        for (int i = 0; i < data.size(); i++){
            // 如果出现过 删除
            if (hash.find(data[i]) != hash.end()){
                hash.erase(data[i]);
            }
            // 如果没出现过 插入
            else{
                hash.insert(data[i]);
            }
        }
        vector<int> temp;
        for (set<int>::iterator i = hash.begin(); i != hash.end(); i++){
            temp.push_back(*i);
        }
        *num1 = temp[0];
        *num2 = temp[1];
    }
};