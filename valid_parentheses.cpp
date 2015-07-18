class Solution {
public:
    bool isValid(string s) {
        std::stack<char> bracket;
        for(std::string::const_iterator cit = s.begin(); cit != s.end(); cit++)
        {
            if(*cit == '(' || *cit == '[' || *cit == '{')
            {
                bracket.push(*cit);
            }
            if(*cit == ')' || *cit == ']' || *cit == '}')
            {
                if(bracket.empty())
                {
                    return false;
                }
                
                char temp = bracket.top();
                bracket.pop();
                if(!is_valid_bracket(temp, *cit))
                {
                    return false;
                }
            }
        }
        return bracket.empty();
    }
    
    bool is_valid_bracket(char left, char right)
    {
        if(left == '(' && right == ')')
        {
            return true;
        }
        if(left == '[' && right == ']')
        {
            return true;
        }
        if(left == '{' && right == '}')
        {
            return true;
        }
        return false;
    }
};