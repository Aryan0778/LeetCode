class Solution {
public:
    bool isValid(vector<int>pre,vector<int>count){
      for(int i=0;i<26;i++){
        if(pre[i]<count[i]) return false;
      }
      return true;
    }
    long long validSubstringCount(string s, string target) {
        long long n=s.size(),m=target.size(),a=0,ans=0;
        vector<int>count(26,0),pre(26,0);
        for(auto it:target) count[it-'a']++;
        for(int i=0;i<n;i++){
          pre[s[i]-'a']++;
          while(a<=i && isValid(pre,count)){
            ans+=(n-i);
            pre[s[a]-'a']--;
            a++;
          }
        }
        return ans;
    }
};