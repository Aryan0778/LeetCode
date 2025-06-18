class Solution {
public:
    void gen(vector<int>&ans,int i,int n){
      if(i>n) return;
      ans.push_back(i);
      int j=0;
      if(i==0){
        j=1;
      }
      for(;j<=9;j++){
        gen(ans,i*10+j,n);
      }
    }
    vector<int> lexicalOrder(int n) {
      vector<int>ans;
      gen(ans,0,n);
      ans.erase(ans.begin(),ans.begin()+1);  
      return ans;
    }
    
};