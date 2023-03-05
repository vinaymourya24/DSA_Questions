class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        int p1=0,p2=0,p3=-1;
        while(p1<haystack.size())
        {
            p3=p1;
            bool f=1;
            while(haystack[p1]==needle[p2])
            {
                f=0;
                if(p2==needle.size()-1) return p3;
                p1++;
                p2++;
            }
            p2=0;
            p1=p3;
             p1++;
        }
        return -1;
    }
};