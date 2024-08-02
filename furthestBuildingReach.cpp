class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i = 0;

        for (i = 0; i < n - 1; i++) {  
            if (heights[i + 1] <= heights[i]) continue;
            
            int diff = heights[i + 1] - heights[i];
            if (diff <= bricks) {
                bricks -= diff;
                pq.push(diff);
            } else if (ladders > 0) {
                if (!pq.empty() && pq.top() > diff) {
                    bricks += pq.top();
                    pq.pop();
                    pq.push(diff);
                    bricks -= diff;
                }
                ladders--;
            } else {
                break;
            }
        }

        return i;
    }
};
