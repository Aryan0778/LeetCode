class Solution {
public:
    int minSwaps(string s) {
    int n=s.size(),count=0;
    for(auto it:s) it=='1'?count++:count--;
    if(abs(count)>1) return -1;
    int c1=0,c2=0;
    bool flag=true;
    for(int i=0;i<n;i++){
    if(flag){
        if(s[i]!='1') c1++;
        flag=false;
    }
    else{
        if(s[i]!='0') c1++;
        flag=true;
    }
    }
    flag=true;
    for(int i=0;i<n;i++){
    if(flag){
        if(s[i]!='0') c2++;
        flag=false;
    }
    else{
        if(s[i]!='1') c2++;
        flag=true;
    }
    }
    int ans=min(ceil((c1*1.0)/2.0),ceil((c2*1.0)/2.0));
    return ans;
    }
};