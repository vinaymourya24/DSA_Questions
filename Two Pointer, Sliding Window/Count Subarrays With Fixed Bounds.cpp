class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        bool isMini=0,isMaxi=0;
        long long leftBound=0,rightBound=0,start=0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<minK || nums[i]>maxK) {
                isMini=0;
                isMaxi=0;
                start=i+1;
                continue;
            }
            
            if(nums[i]==minK)
            {
               isMini=1;
               leftBound=i;
            }

            if(nums[i]==maxK)
            {
                isMaxi=1;
                rightBound=i;
            }

            if(isMini && isMaxi)
            {
                ans+=(min(leftBound,rightBound)-(start)+1);
            }
        }

        return ans;
    }
};