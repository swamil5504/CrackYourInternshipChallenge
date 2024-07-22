class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> s;

        for (int i = 0; i <= n; ++i) {
           
            int currHeight = (i == n) ? 0 : heights[i];

            while (!s.empty() && currHeight < heights[s.top()]) {
                int top = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                int area = heights[top] * width;
                maxArea = max(maxArea, area);
            }

            s.push(i);
        }

        return maxArea;
    }
};
