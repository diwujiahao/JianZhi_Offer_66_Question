class Solution {
    vector<int> ugly_number = vector<int>(1, 1);
    int point2 = 0, point3 = 0, point5 = 0;
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 7){
            return index;
        }
        while(ugly_number.size() < index){
            int n2 = ugly_number[point2] * 2;
            int n3 = ugly_number[point3] * 3;
            int n5 = ugly_number[point5] * 5;
            int temp = min(n2, min(n3, n5));
            if (n2 == temp){
                point2++;
            }
            if (n3 == temp){
                point3++;
            }
            if (n5 == temp){
                point5++;
            }
            ugly_number.push_back(temp);
        }
        return ugly_number[index-1];
    }
};