class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
    int n=s.size(),count=0,a=0,len=INT_MIN;
    for(int i=0;i<n;i++){
        count+=abs(s[i]-t[i]);
        while(count>maxCost){
            count-=abs(s[a]-t[a]);
            a++;
        }
        len=max(len,i-a+1);
    }   
    return len==INT_MIN?0:len;
    }
};