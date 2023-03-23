class Solution {
private:
    bool isPossible(vector<int> &position,int m,int distance)
    {
        int left=position[0];
        m--;
        int i=1;

        while(i<position.size() && left<=position.back() && m>0)
        {
            left+=distance;
            while(i<position.size() && left>position[i]) i++;
           while(i<position.size() && left<position[i])
              left+=distance;
            if(i<position.size())
            {
                left=position[i];
                m--;
                i++;
            }
        }

        if(m==0) return true;
        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1,high=position.back();
        int ans=-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(isPossible(position,m,mid)){
                ans=mid;
                low=mid+1;
            }
            else
            {
               high=mid-1;
            }
        }
        return ans;
    }
};