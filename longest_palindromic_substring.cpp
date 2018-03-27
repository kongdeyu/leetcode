class Solution {
public:
    string longestPalindrome(string s) {
        std::string res;
        if (s.empty()) {
            return res;
        }

        res = std::string(s.begin(), s.begin() + 1);
        for (std::string::const_iterator cit = s.begin(); cit != s.end() - 1; cit++) {
            for (int shift = 0; shift < 2; shift++) {
                std::string::const_iterator left = cit;
                std::string::const_iterator right = cit + shift;

                while (left >= s.begin() && right <= s.end() - 1 && *left == *right) {
                    left--;
                    right++;
                }

                if (res.length() < right - left - 1) {
                    res = std::string(left + 1, right);
                }
            }
        }
        return res;
    }
};
