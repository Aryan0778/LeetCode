class Solution {
public:
    string generateTag(string s) {
        int n=s.size(),i=0;
        string ans="#";
        bool flag=false;
        while(i<n && ans.size()<100){
          if(s[i]==' '){
            flag=true;
            i++;
            continue;
          }
          if(flag){
            ans+=toupper(s[i]);
            flag=false;
          }
          else ans+=tolower(s[i]);
          
          i++;
        }
        ans[1]=tolower(ans[1]);
        return ans;
    }
};