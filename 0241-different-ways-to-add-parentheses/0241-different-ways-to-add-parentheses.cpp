class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
      return solve(s);
    }
    vector<int>solve(string s){
      int n=s.size();
      vector<int>ans;
      for(int i=0;i<n;i++){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
          vector<int>left=solve(s.substr(0,i));
          vector<int>right=solve(s.substr(i+1));
          for(auto x:left){
            for(auto y:right){
              if(s[i]=='+'){
                ans.push_back(x+y);
              }
              else if(s[i]=='-'){
                ans.push_back(x-y);
              }
              else{
                ans.push_back(x*y);
              }
            }
          }
        }
      }
      if(ans.empty()) ans.push_back(stoi(s));
      return ans;
    }
};