class NumArray {
public:
    NumArray(vector<int> &nums) : _arr_size(nums.size()) {
        int sum = 0;
        for(size_t idx = 0; idx < nums.size(); idx++)
        {
            sum += nums[idx];
            _vec_sum.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        assert(i >=0 && j <= _arr_size && i <= j);
        
        if(_vec_sum.empty())
        {
            return 0;
        }
        
        if(i == 0)
        {
            return _vec_sum[j];
        }
        else
        {
            return _vec_sum[j] - _vec_sum[i - 1];
        }
    }
    
private:
    size_t _arr_size;
    std::vector<int> _vec_sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);