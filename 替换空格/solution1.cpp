class Solution {
public:
    void replaceSpace(char *str,int length) {
        // 统计空格个数 space_count
        // 统计 str 长度 len_str
        int space_count = 0, len_str = 0;
        for (int i = 0; str[i] != '\0'; i++){
            len_str++;
            if (str[i] == ' '){
                space_count++;
            }
        }
        // 倒序装入（避免了大量移动）
        int point_old = len_str, point_new = len_str + space_count * 2;
        while (point_old >= 0){
            if (str[point_old] == ' '){
                str[point_new] = '0';
                str[point_new-1] = '2';
                str[point_new-2] = '%';
                point_new -= 2;
            }
            else{
                str[point_new] = str[point_old];
            }
            point_new--;
            point_old--;
        }
    }
};