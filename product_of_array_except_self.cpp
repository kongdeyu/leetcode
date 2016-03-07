class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        assert(nums.size());
        
        product_except_self(nums, 1, 0, nums.size());
        
        return nums;
    }
    
private:
    int product_except_self(std::vector<int> &nums, int backward_product, int idx, int size)
    {
        int forward_product = 1;
        if(idx < size)
        {
            forward_product = product_except_self(nums, backward_product * nums[idx], idx + 1, size);
            int temp = nums[idx];
            nums[idx] = backward_product * forward_product;
            forward_product *= temp;
        }
        return forward_product;
    }
};