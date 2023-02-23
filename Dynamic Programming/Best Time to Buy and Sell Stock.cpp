class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> current_max;
        
        int maxi=0;
        
        for(int i=prices.size()-1; i>=0; i--)
        {
            maxi=max(maxi,prices[i]);
            current_max.push_back(maxi);
        }
        
        reverse(current_max.begin(),current_max.end());
        
        int ans=0;
        
        for(int i=0; i<prices.size(); i++)
        {
            ans=max(ans,(current_max[i]-prices[i]));
            // cout<<current_max[i]<<" "<<prices[i]<<endl;
        }
        
        return ans;
    }
};