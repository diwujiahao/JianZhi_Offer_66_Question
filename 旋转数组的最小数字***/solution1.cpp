class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0){
            return 0;
        }
        for (int i = 0; i < rotateArray.size() - 1; i++){
            if (rotateArray[i] > rotateArray[i+1]){
                return rotateArray[i+1];
            }
        }
        // 旋转数组旋转次数为0
        // 所有元素都一样
        return rotateArray[0];
    }
};