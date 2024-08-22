class Solution {
public:
    int reverse(int x) {
    bool flag=false;
    if(x<0){
        flag=true;
        x=abs(x);
    }
    int ans=0;
    while(x>0){
        int r=x%10;
        if(ans>INT_MAX/10 || ans<INT_MIN/10) return 0;
        ans=ans*10+r;
        x/=10;
    }
    if(flag) return -ans;
    return ans;  
    }
};