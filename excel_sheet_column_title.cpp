class Solution {
public:
    string convertToTitle(int n) {
        assert(n > 0);
        
        std::string res;
        while(n > 0)
        {
            int digit = (n - 1) % 26;
            res.insert(res.begin(), 'A' + digit);
            n = (n - 1) / 26;
        }
        return res;
    }
};