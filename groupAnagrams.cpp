class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map <string, vector<string>> mp;
        for(auto s : strs)
        {
            string oriString = s;
            sort(s.begin(),s.end());
            mp[s].push_back(oriString);
        }

        vector<vector<string>> anagrams;

        for(auto [key,vectorOfStrings] : mp)
        {
            anagrams.push_back(vectorOfStrings);
        }

        return anagrams;
    }
};