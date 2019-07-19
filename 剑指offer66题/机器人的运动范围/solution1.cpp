class Solution {
    vector<vector<bool>> map; //存储地图
    int result = 0; // 存储结果统计-到达格子数目
    //递归函数
    void recursion(int i, int j, int threshold, int rows, int cols){
        // 检查当前位置是否超出格子范围
        if (i < 0 || i >= rows || j < 0 || j >= cols){
            return;
        }
        // 检查当前位置是否遍历过
        if (map[i][j]){
            return;
        }
        // 检查当前位置是否符合阈值
        if (sum(i) + sum(j) > threshold){
            return;
        }
        // 标记当前位置为已路过
        map[i][j] = true;
        result++;
        // 递归
        recursion(i+1,j,threshold,rows,cols);
        recursion(i-1,j,threshold,rows,cols);
        recursion(i,j+1,threshold,rows,cols);
        recursion(i,j-1,threshold,rows,cols);
    }
    // 辅助求和函数
    int sum(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }
    
public:
    int movingCount(int threshold, int rows, int cols){
        // 初始化
        map = vector<vector<bool>>(rows, vector<bool>(cols, false));
        // 递归
        recursion(0,0,threshold,rows,cols);
        // 返回结果
        return result;
    }
};