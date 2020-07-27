/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
    // 求最大公约数
    int gcd (int x, int y){
        // 特殊情况判断
        if (x == 0 && y == 0)
            return 1;
        if (x == 0)
            return y;
        if (y == 0)
            return x;
        // 求最大公约数
        int z = y;
        while(x % y != 0){
            z = x % y;
            x = y;
            y = z;
        }
        return z;
    }
     
    // 输入两个点 Point --- 输出一个直线 Line
    string point2Line(Point point1, Point point2){
        // 计算横纵坐标的差值
        // 利用最大公约数，保证相同比例的差值一样
        int delta_x = point1.x - point2.x;
        int delta_y = point1.y - point2.y;
        if (delta_x < 0){
            delta_x *= -1;
            delta_y *= -1;
        }
        // 最大公约数
        int g = gcd(delta_x, delta_y);
        delta_x /= g;
        delta_y /= g;
        return to_string(delta_x) + "--" + to_string(delta_y);
    };
     
public:
     
    int maxPoints(vector<Point> &points) {
        // 特殊情况判断
        if (points.size() == 1){
            return 1;
        }
        // 最终结果
        int result = 0;
        // 固定一个点i，找出包含这个点的直线最大结果，存在temp_result
        for (int i = 0; i < points.size(); i++){
            // 声明临时变量
            unordered_map<string, int> data; // 直线->点数量
            int base_point_count = 1; // 存储：点i的重合点数量
            int temp_result = 0; // 存储：与当前点i共线的最大点数量
            // 遍历其他点
            for (int j = i + 1; j < points.size(); j++){
                // 遇到与点i重复点 -> 更新 base_point_count
                if (points[i].x == points[j].x && points[i].y == points[j].y){
                    base_point_count += 1;
                    continue;
                }
                // 计算斜率的表示
                string temp_line = point2Line(points[i], points[j]);
                // 更新当前斜率的最大点数
                if (data.find(temp_line) == data.end()){
                    data[temp_line] = 0;
                }
                data[temp_line] += 1;
                // 更新临时结果
                temp_result = max(temp_result, data[temp_line]);
            }
            // 更新最终结果
            result = max(result, temp_result + base_point_count);
        }
        return result;
    }
     
};