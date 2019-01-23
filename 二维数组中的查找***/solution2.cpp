// 从左下角或右上角开始
// 充分利用行列递增信息

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i = array.size()-1, j = 0;
        while (i >= 0 && j < array[0].size()){
            if (array[i][j] > target){
                i--;
            }
            else if (array[i][j] < target){
                j++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
