class Solution {
private:
    bool timeTakesToEat(int mid,int h,vector<int> piles)
    {
        if(mid==0) return false;
       long time = 0;
 
       for(auto v:piles)
       {
          time += (v/mid) + (v%mid!=0);
       }

       if(time<=h) return true;
       return false;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int low=1,high=piles.size()+1;
       for(auto v:piles)
       {
           high=max(high,v);
       }
       int ans = low;

       while(low<=high)
       {
           int mid = low + (high - low)/2;

           bool check = timeTakesToEat(mid,h,piles); 

           if(check==true)
           {
               ans=mid;
               high=mid-1;
           }
           else
           {
              low=mid+1;
           }
       }
     
       return ans;
    }
};