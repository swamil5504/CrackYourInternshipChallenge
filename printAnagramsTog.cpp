class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string,vector<string>> mp;
        for(int i = 0; i < string_list.size();i++)
        {
            string s = string_list[i];
            sort(s.begin(),s.end());
            mp[s].push_back(string_list[i]);
        }
        
         vector<vector<string>> ans(mp.size());
         int idx = 0;
         
         for(auto x : mp)
         {
             auto v = x.second;
             
             for(int i = 0; i < v.size();i++)
             {
                 ans[idx].push_back(v[i]);
             }
             idx++;
         }
         return ans;
        
    }
};