class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        
        sort(s.begin(),s.end());
        string n1,n2;
        for(int i=0; i<s.size(); i++)
        {
            if(i&1)
            {
               n2.push_back(s[i]);  
            } 
            else
            {
                n1.push_back(s[i]);
            }
        }
        
        cout<<n1<<" "<<n2<<endl;
        int num1=0,num2=0;
        
        int i=0;
        while(i<n1.size())
        {
            num1=num1*10+(n1[i]-'0');
            i++;
        }
        i=0;
        while(i<n2.size())
        {
            num2=num2*10+(n2[i]-'0');
            i++;
        }
        
        return num1+num2;
    }
};