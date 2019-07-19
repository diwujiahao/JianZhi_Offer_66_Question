class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0, right = int(rotateArray.size()) - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if (rotateArray[mid] < rotateArray[right]){
                // 保证右指针始终保持在右半边（最小值及其右边）
                // 没有加一
                right = mid;
            }
            else if (rotateArray[mid] > rotateArray[right]){
                left = mid + 1;
            }
            else{
                // 保证右指针始终保持在右半边（最小值及其右边）
                // 进行判断，如果找到转折点则返回
                if (rotateArray[right] >= rotateArray[right - 1]){
                    right--;
                }
                else{
                    return rotateArray[right];
                }
            }
        }
        return rotateArray[left];
    }
};