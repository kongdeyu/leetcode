class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        std::vector<int> ch2idx(128, -1);
        int begin = 0;
        int end = 0;
        while (end < s.size()) {
            begin = std::max(begin, ch2idx[s.at(end)] + 1);
            max_length = std::max(max_length, end - begin + 1);
            ch2idx[s.at(end)] = end;
            end++;
        }
        return max_length;
    }
};
