class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        assert(nums.size());
        k %= nums.size();
        rotate(nums.begin(), nums.end() - k - 1);
        rotate(nums.end() - k, nums.end() - 1);
        rotate(nums.begin(), nums.end() - 1);
    }
    
    void rotate(std::vector<int>::iterator start, std::vector<int>::iterator stop)
    {
        while(start < stop)
        {
            std::swap(*(start++), *(stop--));
        }
    }
};