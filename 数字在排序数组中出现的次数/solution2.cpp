class Solution {
    int binary_search(vector<int> data, int k){
        int left = 0, right = data.size()-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if (data[mid] > k){
                right = mid - 1;
            }
            else if (data[mid] < k){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.size() == 0){
            return 0;
        }
        int count = 1;
        int index = binary_search(data, k);
        if (index < 0){
            return 0;
        }
        int point = index - 1;
        while(data[point] == k && point >= 0){
            count++;
            point--;
        }
        point = index + 1;
        while(data[point] == k && point <= data.size()-1){
            count++;
            point++;
        }
        return count;
    }
};
