class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int fuel=0;
        int start=0;
        int n = gas.size();
        int totalGas=accumulate(gas.begin(),gas.end(),0);
        int requiredGas=accumulate(cost.begin(),cost.end(),0);
        if(requiredGas>totalGas)
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            fuel=(fuel+gas[i])-cost[i];

            if(fuel<0)
            {
                start=i+1;
                fuel=0;
            }
        }   
        return start;
    }
};