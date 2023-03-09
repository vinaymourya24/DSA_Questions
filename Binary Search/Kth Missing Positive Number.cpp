class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0,high=arr.size()-1;
    
        while(low<=high)
        {
            int mid = (low + (high-low));
            if(arr[mid]-(mid+1)<k) {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        return low+k;
    }
};