class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int n=s.size(),ans=0;
        for(int i=1;i<n;++i){
          int j=i,cnt=1;
          while(j<n && s[j-1]<=s[j]){
            if(s[j-1]<s[j]) cnt++;
            j++;
          }
          if(cnt==5) ans=max(ans,j-i+1);
          cout<<j<<" ";
          i=j;
          cout<<i<<endl;
        }
        return ans;
    }
};