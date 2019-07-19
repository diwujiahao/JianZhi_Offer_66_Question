class Solution {
    int get_max(int left, int right, vector<int> num){
        int temp_max = INT_MIN;
        for (int i = left; i <= right; i++){
            temp_max = max(temp_max, num[i]);
        }
        return temp_max;
    }
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int left = 0, right = size - 1;
        vector<int> result;
        while (right < num.size()){
            result.push_back(get_max(left,right,num));
            left++;right++;
        }
        return result;
    }
};