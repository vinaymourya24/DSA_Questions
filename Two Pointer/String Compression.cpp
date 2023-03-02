class Solution{
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1) return 1;
        vector<char> ans;
        int p1=0,p2=0;
        while(p1<chars.size())
        {
            while(p2<chars.size() && chars[p1]==chars[p2])
            {
                p2++;
            }

            if(p2-p1==1)
            {
                ans.push_back(chars[p1]);
                p1++;
            }
            else
            {
               ans.push_back(chars[p1]);
               int num = p2 - p1;
               string count = to_string(num);
               for(auto v:count)
               {
                   ans.push_back(v);
               }
            }

            p1=p2;
            // if(p1==chars.size()-1) break;
        }
        
        chars.clear();
        chars=ans;
        return ans.size();
    }
};