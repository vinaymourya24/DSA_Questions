class Solution {
public:
    long long coloredCells(int n) {
        vector<long long> ans;
        for(int i=0; i<n; i++)
        {
            if(i==0) ans.push_back(1);
            else
            {
                ans.push_back(ans.back()+4*(i));
            }
        }
        
        return ans.back();
    }
};