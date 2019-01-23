class Solution {
    const vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}}; // 方向
    int direction_index = 0; // 方向索引
    const int label = INT_MAX; // 路过标记
    vector<int> result; // 存储结果
    // 检查下一步是否需要更换前进方向
    void check_direction(int i, int j, vector<vector<int>> matrix){
        i += direction[direction_index][0];
        j += direction[direction_index][1];
        // 超出范围
        if (i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0 ){
            direction_index = (direction_index + 1) % 4;
        }
        // 碰到走过的点
        else if (matrix[i][j] == label){
            direction_index = (direction_index + 1) % 4;
        }
    }
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        int i = 0, j = 0;
        while(i < matrix.size() && i >= 0 && j < matrix[0].size() && j >= 0 && matrix[i][j] != label){
            // 填充数据并标记
            result.push_back(matrix[i][j]);
            matrix[i][j] = label;
            // 检查修改方向
            check_direction(i, j, matrix);
            // 前进一步
            i += direction[direction_index][0];
            j += direction[direction_index][1];
        }
        return result;
    }
};