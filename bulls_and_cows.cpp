class Solution {
public:
    string getHint(string secret, string guess) {
        assert(secret.size() == guess.size());
        
        int bulls = 0;
        int cows = 0;
        
        std::vector<int> idr2secret(secret.size(), 0);
        std::vector<int> idr2guess(guess.size(), 0);
        
        for(size_t idx = 0; idx < secret.size(); idx++)
        {
            if(secret[idx] == guess[idx])
            {
                bulls++;
                idr2secret[idx] = 1;
                idr2guess[idx] = 1;
            }
        }
        
        for(size_t idx2sec = 0; idx2sec < secret.size(); idx2sec++)
        {
            if(idr2secret[idx2sec] == 1)
            {
                continue;
            }
            
            for(size_t idx2gue = 0; idx2gue < guess.size(); idx2gue++)
            {
                if(idr2guess[idx2gue] == 0 && secret[idx2sec] == guess[idx2gue])
                {
                    cows++;
                    idr2secret[idx2sec] = 1;
                    idr2guess[idx2gue] = 1;
                    break;
                }
            }
        }
        
        std::stringstream ss;
        ss << bulls << 'A' << cows << 'B';
        return ss.str();
    }
    
};