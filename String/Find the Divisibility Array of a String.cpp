class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size(),0);
        
        long long sum = 0;
        
        for(int i=0; i<word.size(); i++)
        {
           sum = sum * 10 + (word[i]-'0')*1ll;
            if(sum%m==0)
            {
                ans[i]=1;
            }
            sum = sum%m;
        }
        
        return ans;
    }
};