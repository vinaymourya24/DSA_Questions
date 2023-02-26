class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size(),0),rightSum(nums.size(),0);
        int temp = 0;
        for(int i=1; i<nums.size(); i++)
        {
            temp+=nums[i-1];
            leftSum[i]=temp;
        }
        
        temp=0;
        for(int i=nums.size()-2; i>=0; i--)
        {
            temp+=nums[i+1];
            rightSum[i]=temp;
        }
        
//         for(auto v:leftSum) cout<<v<<" ";
//         cout<<endl;
        
//         for(auto v:rightSum) cout<<v<<" ";
//         cout<<endl;
        
        vector<int> ans(nums.size(),0);
        
        for(int i=0; i<nums.size(); i++)
        {
            ans[i] = abs(leftSum[i]-rightSum[i]);
        }
        
        return ans;
    }
};