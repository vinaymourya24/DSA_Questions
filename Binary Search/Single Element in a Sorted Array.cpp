int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low=0,high=nums.size()-2;
        if(nums[low]!=nums[low+1]) return nums[low];
        else if(nums[high]!=nums[high+1]) return nums[high+1];
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) {return nums[mid];}
            else if(mid&1)
            {
                if(nums[mid]==nums[mid-1])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            else
            {
                if(nums[mid]==nums[mid+1])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }    
        return -1;
    }