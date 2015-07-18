class Solution {
public:
    bool isHappy(int n) {
        std::set<int> nums;
        nums.insert(n);
        int new_num = n;
        while(new_num != 1)
        {
            int temp = 0;
            while(new_num > 0)
            {
                temp += pow(new_num % 10, 2);
                new_num /= 10;
            }
            new_num = temp;
            if(nums.find(new_num) != nums.end())
            {
                return false;
            }
            nums.insert(new_num);
        }
        return true;
    }
};