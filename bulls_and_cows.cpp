class Solution {
public:
    string getHint(string secret, string guess) {
        assert(secret.size() == guess.size());
        
        int bulls = 0;
        int cows = 0;
        
        std::vector<int> count(128, 0);
        for(size_t idx = 0; idx < secret.size(); idx++)
        {
            if(secret[idx] == guess[idx])
            {
                bulls++;
            }
            else
            {
                char ch = secret[idx];
                count[ch]++;
                if(count[ch] <= 0)
                {
                    cows++;
                }
                ch = guess[idx];
                count[ch]--;
                if(count[ch] >= 0)
                {
                    cows++;
                }
            }
        }
        
        std::stringstream ss;
        ss << bulls << 'A' << cows << 'B';
        return ss.str();
    }
    
};