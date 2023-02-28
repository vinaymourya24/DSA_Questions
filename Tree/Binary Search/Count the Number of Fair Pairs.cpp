long long countFairPairs(vectorint& nums, int lower, int upper) {
        // first sort the input because we don't wan't contiguouos
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0; inums.size(); i++)
        {
           // updated lowerbound and upperbound
            int lower1 = lower-nums[i],upper1 = upper-nums[i];
            
            if(upper_bound(nums.begin()+i+1,nums.end(),upper1)=lower_bound(nums.begin()+i+1,nums.end(),lower1))
            {
              ans+=(upper_bound(nums.begin()+i+1,nums.end(),upper1)-lower_bound(nums.begin()+i+1,nums.end(),lower1));   
            }
        
        }
        return ans;
    }