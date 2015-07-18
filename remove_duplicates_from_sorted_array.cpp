class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::vector<int>::iterator fast = nums.begin();
        std::vector<int>::iterator slow = nums.begin();
        while(slow != nums.end())
        {
            if(*slow == *fast)
            {
                slow++;
            }
            else
            {
                *(++fast) = *(slow++);
            }
        }
        nums.erase(fast + 1, nums.end());
        return fast - nums.begin() + 1;
    }
};