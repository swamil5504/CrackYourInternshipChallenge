class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxA = 0;

        while(left < right)
        {
            int currA = min(height[left],height[right]) * (right - left);
            maxA = max(maxA,currA);

            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
           
        }
         return maxA;
    }
};