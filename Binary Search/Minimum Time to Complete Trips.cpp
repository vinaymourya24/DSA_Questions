class Solution {
private: 
    long long findMinimumTrips(vector<int> &time,long long mid)
    {
        long long trips=0;
        for(int i=0; i<time.size(); i++)
        {
            trips+=(mid/(long long)time[i]);
        }
        return trips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
         long long ans=((long long)time[0])*totalTrips,low=0,high=ans;
         while(low<=high)
         {
             if(low==high) break;
             long long mid = low + (high - low)/2;

             if(findMinimumTrips(time,mid)>=totalTrips)
             {
                 ans=min(ans,mid);
                 high=mid;
             }
             else low=mid+1;
         }

         return ans;
    }
};