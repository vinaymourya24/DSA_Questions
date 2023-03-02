class Solution {
// private:
//     void solve(int i,vector<int> &nums,vector<int> &ans,vector<int> temp,vector<vector<int>> &dp)
//     {
//         if(i==nums.size()) return;
//         if(i==0 || temp.empty() || nums[i]%temp.back()==0)
//         {

//             temp.push_back(nums[i]);
//             solve(i+1,nums,ans,temp);
//             if(temp.size()>ans.size()) ans=temp;
//             temp.pop_back();  
//         }

//         solve(i+1,nums,ans,temp);
//         if(temp.size()>ans.size()) ans=temp;
//     }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0) return {0};
        sort(nums.begin(),nums.end());
        int maxi=1,maxIndex=0;
        vector<int> dp(nums.size(),1),hash(nums.size(),0);

        for(int i=1; i<nums.size(); i++)
        {
            hash[i]=i;
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];

                    hash[i]=j;
                }
            }
                if(maxi<dp[i])
                {
                    maxi=max(dp[i],maxi);
                    maxIndex=i;
                }
        }
        vector<int> ans;
        while(hash[maxIndex]!=maxIndex)
        {
            ans.push_back(nums[maxIndex]);
            maxIndex=hash[maxIndex];
        }
        ans.push_back(nums[maxIndex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
