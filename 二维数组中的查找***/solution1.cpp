// 二分查找 遍历每一行

class Solution {
    
    bool binary_search(vector<int> data, int target){
        int left = 0, right = data.size() - 1;
        while (left <= right){
            int mid = (left + right) / 2;
            if (data[mid] > target){
                right = mid - 1;
            }
            else if (data[mid] < target){
                left = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
public:
    bool Find(int target, vector<vector<int> > array) {
        for (int i = 0; i < array.size(); i++){
            if (binary_search(array[i], target)){
                return true;
            }
        }
        return false;
    }
};