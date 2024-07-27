class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool digitS = false, eS = false, dotS = false;
        int countPlusMinus = 0;

        for(int i = 0; i < n; i++)
        {
            // digit
            if(isdigit(s[i]))
            {
                digitS = true;
            }
            // minus/plus
            else if(s[i] == '+' || s[i] == '-')
            {
                countPlusMinus++;
                if(countPlusMinus > 2)
                {
                    return false;
                }

                if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E'))
                {
                    return false;
                }

                if(i == n-1)
                {
                    return false;
                }
            }
            // dot
            else if(s[i] == '.')
            {
                if(eS || dotS)
                {
                    return false;
                }
                dotS = true;
                if(i == n-1 && !digitS)
                {
                    return false;
                }
            }
            // E/e
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(eS || !digitS || i == n-1)
                {
                    return false;
                }
                eS = true;
                countPlusMinus = 0; // reset plus/minus count after 'e'
            }
            // invalid character
            else
            {
                return false;
            }
        }
        
        return digitS;
    }
};
