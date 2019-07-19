class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (k > input.size()){
            return result;
        }
        make_heap(input.begin(), input.end(), greater<int>());
        while(k--){
            pop_heap(input.begin(), input.end(), greater<int>());
            result.push_back(input.back());
            input.pop_back();
        }
        return result;
    }
};