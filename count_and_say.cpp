class Solution {
public:
    string countAndSay(int n) {
        std::string pre("1");
        for(int32_t i = 2; i <= n; i++)
        {
            std::stringstream ss;
            char ch = pre.front();
            int32_t times = 1;
            for(std::string::const_iterator cit = pre.begin() + 1; cit != pre.end(); cit++)
            {
                if(*cit == ch)
                {
                    times++;
                }
                else
                {
                    ss << times << ch;
                    ch = *cit;
                    times = 1;
                }
            }
            ss << times << ch;
            ss >> pre;
        }
        return pre;
    }
};