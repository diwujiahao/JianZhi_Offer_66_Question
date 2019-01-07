// 逆序 = 排序交换次数
// 每一个相邻的交换产生一个逆序

// 利用归并排序，并统计相邻交换次数
// 归并排序是因为时间复杂度要求

class Solution {
    long long count = 0;
    // 归并排序
    void merge_sort(vector<int>& data, int start, int end){
        if (start >= end){
            return;
        }
        int mid = (start + end) / 2;
        merge_sort(data, start, mid);
        merge_sort(data, mid+1, end);
        merge(data, start, mid, end);
    }
    // 原地归并
    void merge(vector<int>& data, int start, int mid, int end){
        int i = start, j = mid + 1;
        vector<int> copy;
        for (int index = start; index <= end; index++){
            copy.push_back(data[index]);
        }
        for (int k = 0; k < copy.size(); k++){
            if (i > mid){
                data[k+start] = copy[j++ - start];
            }
            else if (j > end){
                data[k+start] = copy[i++ - start];
            }
            else if (copy[i - start] <= copy[j - start]){
                data[k+start] = copy[i++ - start];
            }
            else {
                count += j - (start + k); // core code : 相邻逆序统计
                data[k+start] = copy[j++ - start];
            }
        }
    }
public:
    int InversePairs(vector<int> data) {
        merge_sort(data, 0, int(data.size())-1);
        return count%1000000007;
    }
};



// 修改版
// 将copy声明为类变量，修改了原地归并的角标。
class Solution {
    long long count = 0;
    vector<int> copy;
    void merge_sort(vector<int>& data, int start, int end){
        if (start >= end){
            return;
        }
        int mid = (start + end) / 2;
        merge_sort(data, start, mid);
        merge_sort(data, mid+1, end);
        merge(data, start, mid, end);
    }
    void merge(vector<int>& data, int start, int mid, int end){
        int i = start, j = mid + 1;
        for (int index = start; index <= end; index++){
            //            copy.push_back(data[index]);
            copy[index] = data[index];
        }
        for (int k = start; k <= end; k++){
            if (i > mid){
                data[k] = copy[j++];
            }
            else if (j > end){
                data[k] = copy[i++];
            }
            else if (copy[i] <= copy[j]){
                data[k] = copy[i++];
            }
            else {
                count += j - k;
                data[k] = copy[j++];
            }
        }
    }
public:
    int InversePairs(vector<int> data) {
        copy = vector<int>(data.size(), 0);
        merge_sort(data, 0, int(data.size())-1);
        return count%1000000007;
    }
};
