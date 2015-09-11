class Solution {
public:
    int addDigits(int num) {
        assert(num >= 0);
        
        return ((num - 1) % 9) + 1;
    }
    
};