class Solution {
private:
    int solve(int index,int kyakharida,vector<int> &prices,vector<vector<int>> &dp)
    {
       if(index>=prices.size()) return 0;
       if(dp[index][kyakharida]!=-1) return dp[index][kyakharida];
       if(kyakharida==1)
       {
           return dp[index][kyakharida] = max(prices[index]*-1 + solve(index+1,0,prices,dp),solve(index+1,1,prices,dp));
       }
       else
       {
           return dp[index][kyakharida] = max(prices[index]+solve(index,1,prices,dp),solve(index+1,1,prices,dp));
       }
    }

public:
    int maxProfit(vector<int>& prices) {
       vector<vector<int>> dp(prices.size(),vector<int> (2,-1)); 
       return solve(0,1,prices,dp);
    }
};