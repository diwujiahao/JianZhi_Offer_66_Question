class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // 特殊情况判断
        if (array.size() == 0){
            return;
        }
        // 原数组长度
        int length = int(array.size());
        // 写入指针
        int point = 0;
        for (int i = 0; i < length; i++){
            // 偶数--先放后面
            if (array[i] % 2 == 0){
                array.push_back(array[i]);
            }
            // 奇数--写入对应位置
            else{
                array[point++] = array[i];
            }
        }
        // 重新写入偶数
        for (int i = length; i < array.size(); i++){
            array[point++] = array[i];
        }
        // 擦除多余部分
        array.erase(array.begin() + length, array.end());
    }
};