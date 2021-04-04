class Solution {
public:
    void parseSign(string &s, int &i) {
        if (s[i] == '+' || s[i] == '-')    
            i++;
    }
    
    bool parseDot(string &s, int &i) {
        if (s[i] == '.') {
            i++;
            return true;
        }
        return false;
    }
    
    bool parseDigit(string &s, int &i) {
        if (s[i] < '0' || s[i] > '9')
            return false;
        while (i < s.length() && (s[i] >= '0' && s[i] <= '9'))
            i++;
        return true;
    }
    
    
    bool isDecimal(string &s, int &i) {
        parseSign(s, i);
        if (parseDigit(s, i) == false) {
            return parseDot(s, i) & parseDigit(s, i);
        }
        
        if (parseDot(s, i) == false)
            return false;
        
        parseDigit(s, i);
        return true;
    }
    
    bool isExponential(string &s, int &i) {
        if (s[i] == 'e' || s[i] == 'E') {
            i++;
            return true;
        }
        return false;
    }
    
    bool isInteger(string &s, int &i) {
        parseSign(s, i);
        return parseDigit(s, i);
    }
    
    bool isNumber(string s) {
        int i = 0;
        if (isDecimal(s, i) == false) {
            i = 0;
            if (isInteger(s, i) == false)
                return false;
        }
    
        if (i < s.length() && isExponential(s, i)) 
            return isInteger(s, i) & i == s.length();
        return i == s.length();
    }
};