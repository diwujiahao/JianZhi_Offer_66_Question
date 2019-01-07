class Solution {
    // mid:素有数字平均数
    // i:数字个数
    vector<int> create(double mid, int i){
        vector<int> re;
        // 分割份数为奇数 && mid为整数
        if (i % 2 == 1 && int(mid) == mid){
            for (int temp = mid - i/2; temp <= mid + i/2; temp++){
                re.push_back(temp);
            }
        }
        // 分割份数为偶数 && mid为0.5
        else if (i % 2 == 0 && mid - int(mid) == 0.5){
            for (int temp = int(mid) - i/2 + 1; temp <= mid + i/2; temp++){
                re.push_back(temp);
            }
        }
        // 无法正确分割
        else{
            return re;
        }
        return re;
    }
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        // 找到切分最多的份数
        int top = 0;
        for (int i = 1; i < sum; i++){
            top += i;
            if (top > sum){
                top = i;
                break;
            }
        }
        // 遍历分割的份数
        for (int i = top - 1; i > 1; i--){
            double mid = double(sum) / double(i);
            // 分割份数为奇数 && mid为整数
            if (i % 2 == 1 && int(mid) == mid){
                result.push_back(create(mid, i));
            }
            // 分割份数为偶数 && mid为0.5
            else if (i % 2 == 0 && mid - int(mid) == 0.5){
                result.push_back(create(mid, i));
            }
            // 无法正确分割
            else{
                continue;
            }
        }
        return result;
    }
};