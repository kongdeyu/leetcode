class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(s == 0 || nums.empty())
        {
            return 0;
        }
        
        int min_length = INT_MAX;
        int fast = 0;
        int slow = 0;
        int sum = 0;
        while(slow < nums.size())
        {
            while(sum < s && fast < nums.size())
            {
                sum += nums[fast++];
            }
            
            if(sum < s)
            {
                break;
            }
            
            min_length = std::min(min_length, fast - slow);
            sum -= nums[slow++];
            fast = std::max(slow, fast);
        }
        
        return min_length == INT_MAX ? 0 : min_length;
    }
};