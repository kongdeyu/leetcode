class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        if(numbers.size() < 2)
        {
            return res;
        }
        
        vector<pair<int, int> > input;
        int index = 1;
        for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        {
            input.push_back(make_pair(*it, index++));
        }
        sort(input.begin(), input.end(), Solution::compare);
        
        vector<pair<int, int> >::iterator begin = input.begin();
        vector<pair<int, int> >::iterator end = input.end() - 1;
        while(begin < end)
        {
            if(begin->first + end->first == target)
            {
                if(begin->second < end->second)
                {
                    res.push_back(begin->second);
                    res.push_back(end->second);
                }
                else
                {
                    res.push_back(end->second);
                    res.push_back(begin->second);
                }
                break;
            }
            else if(begin->first + end->first < target)
            {
                begin++;
            }
            else
            {
                end--;
            }
        }
        return res;
    }
};
