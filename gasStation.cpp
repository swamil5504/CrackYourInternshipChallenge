class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int m = cost.size();
        int gasSum = 0;
        int costSum = 0;
        int startGas = 0;
        int currGas = 0;
        
        for(int i = 0; i < n ; i++)
        {
            gasSum  = gasSum + gas[i];
        }

        for(int i = 0; i < m; i++)
        {
            costSum = costSum + cost[i];
        }

        if(gasSum < costSum)
        {
            return -1;
        }

        for(int i = 0; i < n ; i++)
        {
            currGas += (gas[i] - cost[i]);

            if(currGas < 0)
            {
                startGas = i + 1;
                currGas = 0;
            }

        }
        return startGas;
    }
};