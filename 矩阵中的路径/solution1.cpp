class Solution {
    vector<vector<char>> map;
    char label = '*';
    // 递归函数
    bool recursion(int i, int j, int rows, int cols, char* str, int point, vector<vector<char>> temp_map){
        // 检查是否匹配完全
        if (point == strlen(str)){
            return true;
        }
        // 检查是否超出范围
        if (i < 0 || i >= rows || j < 0 || j >= cols){
            return false;
        }
        // 检查是否已走过
        if (temp_map[i][j] == label){
            return false;
        }
        // 检查当前位置是否匹配
        if (temp_map[i][j] == str[point]){
            // 修改当前位置标记
            temp_map[i][j] = label;
            // 递归
            if (recursion(i+1,j,rows,cols,str,point+1,temp_map)){
                return true;
            }
            if (recursion(i-1,j,rows,cols,str,point+1,temp_map)){
                return true;
            }
            if (recursion(i,j+1,rows,cols,str,point+1,temp_map)){
                return true;
            }
            if (recursion(i,j-1,rows,cols,str,point+1,temp_map)){
                return true;
            }
        }
        return false;
    }
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        // 初始化
        map = vector<vector<char>>(rows, vector<char>(cols, ' '));
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                map[i][j] = matrix[cols * i + j];
            }
        }
        // 递归
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (recursion(i,j,rows,cols,str,0,map)){
                    return true;
                }
            }
        }
        return false;
    }
};
