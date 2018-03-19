class Solution {
private:
    bool is_palindromic(std::string::const_iterator cit2begin, std::string::const_iterator cit2end, int cur_min_len) {
        if (cit2end - cit2begin + 1 < cur_min_len) {
            return false;
        }

        while (cit2begin <= cit2end) {
            if (*cit2begin != *cit2end) {
                return false;
            }

            cit2begin++;
            cit2end--;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        std::string res;
        if (s.empty()) {
            return res;
        }

        int cur_min_len = 1;
        for (std::string::const_iterator cit2begin = s.begin(); cit2begin != s.end(); cit2begin++) {
            for (std::string::const_iterator cit2end = cit2begin; cit2end != s.end(); cit2end++) {
                if (is_palindromic(cit2begin, cit2end, cur_min_len)) {
                    cur_min_len = cit2end - cit2begin + 1;
                    res = std::string(cit2begin, cit2end + 1);
                }
            }
        }
        return res;
    }
};
