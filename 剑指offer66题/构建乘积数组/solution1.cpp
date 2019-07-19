class Solution {
    vector<int> data;
    vector<int> data1;
    vector<int> data2;
public:
    vector<int> multiply(const vector<int>& A) {
        data = vector<int>(A.size(), 1);
        data1 = vector<int>(A.size(), 1);
        data2 = vector<int>(A.size(), 1);
        for (int i = 1; i < A.size(); i++){
            data1[i] = data1[i-1] * A[i-1];
        }
        for (int i = int(A.size()) - 2; i >= 0; i--){
            data2[i] = data2[i+1] * A[i+1];
        }
        for (int i = 0; i < A.size(); i++){
            data[i] = data1[i] * data2[i];
        }
        return data;
    }
};
