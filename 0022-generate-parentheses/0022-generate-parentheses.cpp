class Solution {
public:
    void gen(int open,int close,vector<string>&ans,string ds){
      if(open==0 && close==0){
        ans.push_back(ds);
        return;
      }
      
      if(open>0) gen(open-1,close,ans,ds+'(');
      if(open<close && close>0) gen(open,close-1,ans,ds+')');

    }
    vector<string> generateParenthesis(int n) {
      vector<string>ans;
      gen(n,n,ans,"");
      return ans;    
    }
};