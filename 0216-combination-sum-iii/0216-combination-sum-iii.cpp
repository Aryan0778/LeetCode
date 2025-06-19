class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>ds;
    vector<vector<int>>ans;
    gen(1,k,n,ds,ans);
    return ans; 
    }
    void gen(int curr,int k,int n,vector<int>ds,vector<vector<int>>&ans){
    if(k==ds.size()){
      if(n==0){
      ans.push_back(ds);
      }
      return;
    }

    for(int i=curr;i<=9;i++){
      if(n>=i){
      ds.push_back(i);
      gen(i+1,k,n-i,ds,ans);
      ds.pop_back();
      }
    }
    }
};