// 双栈模拟

class Solution {
    vector<int> data;
    vector<int> min_data;
public:
    void push(int value) {
        // 插入数据
        data.push_back(value);
        // 更新最小值
        min_data.push_back((min_data.size() == 0) ? value : std::min(value,min_data.back()) );
    }
    void pop() {
        data.pop_back();
        min_data.pop_back();
    }
    int top() {
        return data.back();
    }
    int min() {
        return min_data.back();
    }
};



class Solution {
    vector<int> data;
    vector<int> min_data;
public:
    void push(int value) {
        // 插入数据
        data.push_back(value);
        // 更新最小值
        if (min_data.size() == 0){
            min_data.push_back(value);
        }
        else if (value <= min_data.back()){
            min_data.push_back(value);
        }
    }
    void pop() {
        if (data.back() == min_data.back()){
            min_data.pop_back();
        }
        data.pop_back();
    }
    int top() {
        return data.back();
    }
    int min() {
        return min_data.back();
    }
};
