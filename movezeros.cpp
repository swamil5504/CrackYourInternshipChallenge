class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0, j = 0; i < len; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};