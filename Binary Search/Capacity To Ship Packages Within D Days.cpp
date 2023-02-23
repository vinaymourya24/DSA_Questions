class Solution {
private:
    bool isPossible(vector<int> & W, int mid, int days){
         int count=0, temp=0;
       for(int i=0;i<W.size();i++){
            temp = temp + W[i];
            if(temp > mid){
                temp = W[i];
                if(W[i]>mid)
                {
                    return false;
                }
                else
                count++;
            }
       }
        count++;
       if(count <= days)
             return true;
        return false;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
          int low =0, high = 0;
          for(int i=0;i<weights.size();i++){
                 high = high + weights[i];
          }
          int ans=high;
          while(low<=high){

              int mid = low + (high-low)/2;
              if(isPossible(weights, mid, days)){
                   ans = min(ans, mid);
                   high = mid-1;
              }
              else
                 low = mid +1;

          }
      return ans;
    }
};