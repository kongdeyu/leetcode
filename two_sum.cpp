class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        if(numbers.size() < 2)
        {
            return res;
        }

        map<int, int> input;
        int index = 0;
        for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        {
            int to_find = target - *it;
            map<int, int>::iterator it_2_find = input.find(to_find);
            if(input.end() == it_2_find)
            {
                input.insert(make_pair(*it, ++index));
            }
            else
            {
                res.push_back(it_2_find->second);
                res.push_back(++index);
                break;
            }
        }
        return res;
    }
};
