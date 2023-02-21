class Solution {
private:
    int solve(int ind1,int isBuy,int chance,vector<int> &prices,vector<vector<vector<int>>> &dp)
    {
       if(ind1==prices.size()) return 0;
       else if(chance<=0) return 0;
    
       if(dp[ind1][isBuy][chance]!=-1) return dp[ind1][isBuy][chance]; //has previously computed
       if(isBuy==0) //For Buy the stocks
       {
          return dp[ind1][isBuy][chance] = max(prices[ind1]*-1 + solve(ind1+1,1,chance,prices,dp),solve(ind1+1,0,chance,prices,dp));
       }
       else // For Sell the stocks
       {
          return dp[ind1][isBuy][chance] = max(prices[ind1] + solve(ind1,0,chance-1,prices,dp),solve(ind1+1,1,chance,prices,dp));
       }
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int> (3, -1)));
        return solve(0,0,2,prices,dp);
    }
};