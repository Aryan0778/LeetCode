class Solution {
public:
    int solve(vector<int>hash,int ind,int n){
      if(ind==n) return 1;
      int count=1;
      for(int i=0;i<=9;i++){
        if(hash[i]!=1 && (i!=0 || ind!=0)){
          hash[i]=1;
          count+=solve(hash,ind+1,n);
          hash[i]=0;
        }
      }
      return count;

    }
    int countNumbersWithUniqueDigits(int n) {
    vector<int>hash(10,0);
    return solve(hash,0,n);   
    }
};