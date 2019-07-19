//双向队列与hash配合使用

class Solution
{
public:
    // 双向队列 存储输入流（存储输入字符对应的ascii的编号）
    deque<int> result;
    // 充当哈希表使用 标记每个字符出现的次数 （ascii一共127个）
    vector<int> table = vector<int>(127, 0);

    //Insert one char from stringstream
    void Insert(char ch)
    {
        table[ch - '\0']++;
        result.push_back(ch - '\0');
    }
    
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while (!result.empty() && table[result.front()] > 1){
            result.pop_front();
        }
        if (result.empty()){
            return '#';
        }
        return result.front();
    }
    
};
