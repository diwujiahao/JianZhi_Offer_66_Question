// 递归实现
class Solution {
    int recursion(int i){
        if (i == 1){
            return 1;
        }
        else{
            return i + recursion(i-1);
        }
    }
    
public:
    int Sum_Solution(int n) {
        return recursion(n);
    }
};
