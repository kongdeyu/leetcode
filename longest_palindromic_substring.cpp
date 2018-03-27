class Solution {
public:
    string longestPalindrome(string s) {
        std::string res;
        if (s.empty()) {
            return res;
        }

        if (s.size() == 1) {
            return s;
        }

        int cur_max_len = 1;
        res = std::string(s.begin(), s.begin() + 1);
        for (std::string::const_iterator cit = s.begin(); cit != s.end() - 1; cit++) {
            for (int shift = 0; shift < 2; shift++) {
                std::string::const_iterator left = cit;
                std::string::const_iterator right = cit + shift;
                if (*left != *right) {
                    break;
                }

                while (left != s.begin() && right != s.end() - 1 && *(left - 1) == *(right + 1)) {
                    left--;
                    right++;
                }

                if (cur_max_len < right - left + 1) {
                    cur_max_len = right - left + 1;
                    res = std::string(left, right + 1);
                }
            }
        }
        return res;
    }
};
