class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::vector<int> ver1 = split(version1);
        std::vector<int> ver2 = split(version2);
        std::vector<int>::size_type idx = 0;
        while(idx < ver1.size() || idx < ver2.size())
        {
            int digit_ver1 = 0;
            if(idx < ver1.size())
            {
                digit_ver1 = ver1[idx];
            }
            int digit_ver2 = 0;
            if(idx < ver2.size())
            {
                digit_ver2 = ver2[idx];
            }
            if(digit_ver1 > digit_ver2)
            {
                return 1;
            }
            if(digit_ver1 < digit_ver2)
            {
                return -1;
            }
            
            idx++;
        }
        return 0;
    }
    
    std::vector<int> split(const std::string &str)
    {
        const char flag = '.';
        std::vector<int> res;
        std::string::const_iterator cit_fast = str.begin();
        std::string::const_iterator cit_slow = str.begin();
        while(cit_slow != str.end())
        {
            if(*cit_slow == flag)
            {
                cit_fast++;
                cit_slow++;
                continue;
            }
            
            if(cit_fast == str.end() || *cit_fast == flag)
            {
                std::string temp(cit_slow, cit_fast);
                if(temp.empty())
                {
                    res.push_back(0);
                }
                else
                {
                    res.push_back(std::stoi(temp));
                }
                cit_slow = cit_fast++;
            }
            else
            {
                cit_fast++;
            }
        }
        return res;
    }
};