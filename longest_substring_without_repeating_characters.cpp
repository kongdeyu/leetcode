class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        int max_length = 1;
        std::vector<int> ch2idx(128, -1);
        std::vector<int>::size_type begin = 0;
        std::vector<int>::size_type end = 0;
        while (end < s.size()) {
            if (ch2idx[s.at(end)] == -1) {
                ch2idx[s.at(end)] = end;
                if (end - begin + 1 > max_length) {
                    max_length = end - begin + 1;
                }
                end++;
                continue;
            }

            if (ch2idx[s.at(end)] >= 0) {
                for (int idx = begin; idx < ch2idx[s.at(end)]; idx++) {
                    ch2idx[s.at(idx)] = -1;
                }
                begin = ch2idx[s.at(end)] + 1;
                ch2idx[s.at(end)] = end;
                end++;
                continue;
            }
        }
        return max_length;
    }
};
