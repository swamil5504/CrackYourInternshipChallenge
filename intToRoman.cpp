
//SOL1

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string ans;
        
        for (int i = 0; i < values.size() && num > 0; ++i) {
            while (num >= values[i]) {
                num -= values[i];
                ans += symbols[i];
            }
        }
        
        return ans;
    }
};


// SOL2
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Correct the map to use int as the key and string as the value
        map<int, string> mpp;
        mpp[1000] = "M";
        mpp[900] = "CM";
        mpp[500] = "D";
        mpp[400] = "CD";
        mpp[100] = "C";
        mpp[90] = "XC";
        mpp[50] = "L";
        mpp[40] = "XL";
        mpp[10] = "X";
        mpp[9] = "IX";
        mpp[5] = "V";
        mpp[4] = "IV";
        mpp[1] = "I";

        string result;

       
        for (auto it = mpp.rbegin(); it != mpp.rend(); ++it) {
            while (num >= it->first) {
                result += it->second;
                num -= it->first;
            }
        }

        return result;
    }
};






