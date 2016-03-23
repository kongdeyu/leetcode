class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        if(n < 0)
        {
            return res;
        }
        
        res = generate_parenthesis("", n, n);
        return res;
    }
    
private:
    std::vector<std::string> generate_parenthesis(std::string str, int left, int right)
    {
        std::vector<std::string> res;
        if(left == 0 && right == 0)
        {
            res.push_back(str);
            return res;
        }
        
        std::vector<std::string> temp;
        if(left > 0)
        {
            temp = generate_parenthesis(str + '(', left - 1, right);
            res.insert(res.end(), temp.begin(), temp.end());
        }
        
        if(right > 0 && right > left)
        {
            temp = generatea_parenthesis(str + ')', left, right - 1);
            res.insert(res.end(), temp.begin(), temp.end());
        }
        
        return res;
    }
};