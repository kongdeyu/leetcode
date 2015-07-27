class Solution {
public:
    string intToRoman(int num) {
        if(num < 1 || num > 3999)
        {
            return "";
        }
        
        std::string res;
        int model = 1;
        while(num > 0)
        {
            std::string temp(int2roman(num % 10, model));
            res.insert(0, temp);
            num /= 10;
            model *= 10;
        }
        return res;
    }
    
private:
    string int2roman(int digit, int model)
    {
        switch(digit * model)
        {
            case 4:
                return "IV";
            case 9:
                return "IX";
            case 40:
                return "XL";
            case 90:
                return "XC";
            case 400:
                return "CD";
            case 900:
                return "CM";
        }
        
        string res;
        if(digit / 5 == 1)
        {
            res.push_back(int2roman_digit(5, model));
        }
        for(int i = 0; i < digit % 5; i++)
        {
            res.push_back(int2roman_digit(1, model));
        }
        return res;
    }
    
    char int2roman_digit(int digit, int model)
    {
        switch(digit * model)
        {
            case 1:
                return 'I';
            case 5:
                return 'V';
            case 10:
                return 'X';
            case 50:
                return 'L';
            case 100:
                return 'C';
            case 500:
                return 'D';
            case 1000:
                return 'M';
            default:
                return '\0';
        }
    }
};