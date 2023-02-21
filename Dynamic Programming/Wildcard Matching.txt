class Solution {
public:
    bool solve(int ind1,int ind2,string &s,string &p,vector<vector<int>> &dp)
    {
        if(ind1<0 && ind2<0) return 1;
        else if(ind2<0) return 0; 
        else if(ind1<0) //remaining characters can be *
        {
            for(int i=0; i<=ind2; i++)
            {
                if(p[i]!='*') return 0;
            }
            return 1;
        }

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        bool check1=0,check2=0;
        if(s[ind1]==p[ind2])
           check1 = solve(ind1-1,ind2-1,s,p,dp);
        else
        {
            if(p[ind2]=='?')
            {
                check2 = solve(ind1-1,ind2-1,s,p,dp);
            }
            else if(p[ind2]=='*') 
            {
                for(int i=0; i<=ind1+1; i++) //check for all the possible values for *
                {
                    check2 += solve(ind1-i,ind2-1,s,p,dp);
                }
            }
        }

        return dp[ind1][ind2] = check1 || check2;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int> (p.size(),-1));
       return solve(s.size()-1,p.size()-1,s,p,dp);
    }
};