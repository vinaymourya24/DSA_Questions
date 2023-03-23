class Solution {
public:
   long  MOD = (long)1e9+7;
   long  mod_multiplication(long a, long b, long m){
    a = a % m; 
    b = b % m; 
     return (((a * b) % m) + m) % m;
   }
    
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        // for(auto v:ranges) 
        // {
        //     cout<<v[0]<<" "<<v[1]<<" ";
        // }
        // cout<<endl;
        long ans=1,temp=ranges[0][1];
        // cout<<temp<<" ";
        for(int i=1; i<ranges.size(); i++)
        {
            if(temp>=ranges[i][0]) ans--;
            ans++;
            if(ranges[i][1]>temp) temp = ranges[i][1];
        }
         cout<<ans<<endl;
        long ans1=2;
        
        for(int i=1; i<ans;i++)
        {
            ans1=(2*ans1)%MOD;
        }
        
        return ans1;
    }
};