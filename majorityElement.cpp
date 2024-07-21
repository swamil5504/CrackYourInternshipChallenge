class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> countMap;
        
        for (int num : nums) {
            countMap[num]++;
        }
        
        for (auto it = countMap.begin(); it != countMap.end(); ++it) {
            if (it->second > n / 2) {
                return it->first;
            }
        }
        
        return -1; 
    }
};
