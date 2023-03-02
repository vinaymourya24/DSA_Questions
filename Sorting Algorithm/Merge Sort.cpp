class Solution {
public:
    void Merge(vector<int> &nums,int low,int mid,int high)
    {
        vector<int> temp;
        int p1=low,p2=mid+1;
        while(p1<=mid && p2<=high)
        {
            if(nums[p1]<nums[p2])
            {
               temp.push_back(nums[p1]);
               p1++;
            }
            else
            {
                temp.push_back(nums[p2]);
                p2++;
            }
        }

        while(p1<=mid)
        {
            temp.push_back(nums[p1]);
            p1++;
        }

        while(p2<=high)
        {
            temp.push_back(nums[p2]);
            p2++;
        }

        for(int i=0; i<temp.size(); i++)
        {
           nums[low]=temp[i];
           low++;
        }
    }

    void MergeSort(vector<int> &nums,int low,int high)
    {
       if(low<high)
       {
          int mid = (high+low)/2;
          MergeSort(nums,low,mid);
          MergeSort(nums,mid+1,high);
          Merge(nums,low,mid,high);  
       } 
    }

    vector<int> sortArray(vector<int>& nums) {
         int low=0,high=nums.size()-1;
         MergeSort(nums,low,high);
        //  reverse(nums.begin(),nums.end());
         return nums;
    }
};