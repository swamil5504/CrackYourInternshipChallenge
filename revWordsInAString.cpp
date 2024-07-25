#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;
        vector<char> rev;

        while (l <= r) {
        
            while (l <= r && s[l] == ' ') l++;
     
            while (l <= r && s[r] == ' ') r--;

            int wordEnd = r;
            while (r >= l && s[r] != ' ') r--;

       
            for (int i = r + 1; i <= wordEnd; i++) {
                rev.push_back(s[i]);
            }

            if (l <= r) {
                rev.push_back(' ');
            }

           
            while (r >= l && s[r] == ' ') r--;
        }

        string result(rev.begin(), rev.end());
        return result;
    }
};

