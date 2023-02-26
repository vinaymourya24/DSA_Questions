class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low =0, high = (nums.size()+1)/2;
        while(high<n)
        {
            if(nums[low]*2<=nums[high]) low++;
            high++;
        }
        return low*2;
    }
};