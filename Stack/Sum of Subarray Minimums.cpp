class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       stack<int> st; //monotonic stack
       int n = arr.size();
       vector<int> leftadjsmall(n),rightadjsmall(n);
       for(int i=0; i<n; i++)
       {
           while(!st.empty() && arr[st.top()]>=arr[i])
           {
               st.pop();
           }

           if(st.empty())
           {
               leftadjsmall[i]=-1;
           }
           else
           {
               leftadjsmall[i]=st.top();
           }
           st.push(i);
       }

       while(!st.empty())
       {
           st.pop();
       }

       for(int i=n-1; i>=0; i--)
       {
           while(!st.empty() && arr[st.top()]>arr[i])
           {
               st.pop();
           }

           if(st.empty())
           {
               rightadjsmall[i]=arr.size();
           }
           else
           {
               rightadjsmall[i]=st.top();
           }
           st.push(i);
       }

        long ans = 0;

       for(int i=0; i<n; i++)
       {
           long temp = i-(leftadjsmall[i]+1)+rightadjsmall[i]-1-i+1;
           long temp2 = (long)(i-(leftadjsmall[i]+1))*(long)(rightadjsmall[i]-1-i);
           temp+=temp2;
           ans+=(arr[i]*temp)%(1000000000+7);
           ans=ans%(1000000000+7);
        //    ans=(ans+(i-leftadjsmall[i]+1)*(rightadjsmall[i]-1-i)*(arr[i]))%(1000000000+7);
        //  cout<<(i-leftadjsmall[i]+1)<<" "<<(rightadjsmall[i]-1-i)<<" "<<arr[i]<<endl;
       }

       return ans;
    }
};