class Solution {
public:
    int jumpFloorII(int number) {
        return (number == 0) ? 0 : pow(2, number - 1);
    }
};