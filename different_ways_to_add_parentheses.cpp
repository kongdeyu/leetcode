class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        std::vector<int> res;
        if(input.empty())
        {
            return res;
        }
        
        for(std::string::iterator cit = input.begin(); cit != input.end(); cit++)
        {
            if(isdigit(*cit))
            {
                continue;
            }
            
            std::vector<int> left = diffWaysToCompute(std::string(input.begin(), cit));
            std::vector<int> right = diffWaysToCompute(std::string(cit + 1, input.end()));
            for(std::vector<int>::const_iterator cit2left = left.begin(); cit2left != left.end(); cit2left++)
            {
                for(std::vector<int>::const_iterator cit2right = right.begin(); cit2right != right.end(); cit2right++)
                {
                    res.push_back(calc(*cit2left, *cit2right, *cit));
                }
            }
        }
        
        if(res.empty())
        {
            int num = 0;
            for(std::string::const_iterator cit = input.begin(); cit != input.end(); cit++)
            {
                int digit = *cit - '0';
                num = num * 10 + digit;
            }
            res.push_back(num);
        }
        return res;
    }
    
private:
    int calc(int left, int right, char op)
    {
        switch(op)
        {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            default:
                return 0;
        }
    }
    
};