class Solution {
public:
    vector<int> minOperations(string s) {
      int n=s.size();
      vector<int>cumSumLeft(n,0),cumSumRight(n,0),ans(n,0);
      cumSumLeft[0]=(s[0]-'0'==1?1:0);
      for(int i=1;i<n;i++){
        cumSumLeft[i]=cumSumLeft[i-1]+s[i]-'0';
      }
      cumSumRight[n-1]=(s[n-1]-'0'==1?1:0);
      for(int i=n-2;i>=0;i--){
        cumSumRight[i]=cumSumRight[i+1]+s[i]-'0';
      }
      int count=cumSumLeft[0];
      for(int i=1;i<n;i++){
        ans[i]=ans[i]+count;
        count+=cumSumLeft[i];
      }
      count=cumSumRight[n-1];
      for(int i=n-2;i>=0;i--){
        ans[i]=ans[i]+count;
        count+=cumSumRight[i];
      }
      for(auto it:cumSumLeft) cout<<it<<" ";
      cout<<endl;
      for(auto it:cumSumRight) cout<<it<<" ";
      cout<<endl;
      for(auto it:ans){
        cout<<it<<" ";
      }
      return ans;
        
    }
};