class Solution {
private: 
    long long Mod = 1e9+7;

public:
    long long findPower(long long base,long long exponent)
    {
       if(exponent==0) return 1;
       long long temp = findPower(base,exponent/2);

       if(exponent&1)
       {
          return ((base*temp)%Mod*temp)%Mod;
       }
       return (temp*temp)%Mod;
    }
    
public:
    int countGoodNumbers(long long n) {
        return (findPower(4,n/2) * findPower(5,(n+1)/2))%Mod;
    }
};