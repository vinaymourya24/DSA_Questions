class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> check(nums2.size(),-1);
        
        for(int i=nums2.size()-1; i>=0; i--)
        {
           if(st.size()==0)
           {
               st.push(nums2[i]);
           }
           else
           {
               if(st.top()<nums2[i])
               {
                   while(!st.empty())
                   {
                       if(st.top()>nums2[i])
                       {
                          check[i]=st.top();
                          break;
                       }
                       st.pop();
                   }
                   st.push(nums2[i]);
               }
               else
               {
                  check[i]=st.top();
                  st.push(nums2[i]);   
               }
           }
        }
        
        unordered_map<int,int> mp;

        for(int i=0; i<nums2.size(); i++)
        {
            mp[nums2[i]]=check[i];
        }

        vector<int> ans = nums1;

        for(int i=0; i<nums1.size(); i++)
        {
           ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};