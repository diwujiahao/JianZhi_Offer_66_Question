class Solution {
    vector<int> nums;
    // 二分查找num应当插入位置i
    int binary_search(int num){
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] > num){
                right = mid - 1;
            }
            else if (nums[mid] < num){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return left;
    }
public:
    void Insert(int num)
    {
        int index = binary_search(num);
        nums.insert(nums.begin() + index, num);
    }

    double GetMedian()
    { 
        // 奇数
        if (nums.size() % 2 == 1){
            return nums[nums.size()/2];
        }
        // 偶数
        else{
            return double(nums[nums.size()/2] + nums[nums.size()/2-1]) / 2;
        }
    }
};