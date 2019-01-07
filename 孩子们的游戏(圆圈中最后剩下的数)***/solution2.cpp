// 数组模拟游戏

class Solution {
    
public:
    int LastRemaining_Solution(int n, int m)
    {
        
        vector<int> number(n, 0);
        for (int i = 0; i < n; i++){
            number[i] = i;
        }
        // 游戏轮数
        int winner = 0; // 每轮获胜编号
        while(number.size() > 1){
            // 从上轮获胜编号开始报数m个人
            int winner = (winner+m-1) % number.size();
            // 删除本轮获胜者
            number.erase(number.begin()+winner);
        }
        return (number.size() > 0) ? number[0] : -1;
    }
};
