class Solution {
public:
    vector<string> letterCombinations(string s) {
      if(s=="") return {};
      map<int,string>mpp;
      mpp[2]="abc";
      mpp[3]="def";
      mpp[4]="ghi";
      mpp[5]="jkl";
      mpp[6]="mno";
      mpp[7]="pqrs";
      mpp[8]="tuv";
      mpp[9]="wxyz";
      vector<string>ans;
      string ds="";
      gen(s,0,ds,ans,mpp);
      return ans;
    }

    void gen(string s,int idx,string ds,vector<string>&ans,map<int,string>mpp){
      if(idx>=s.size()){
        ans.push_back(ds);
        return;
      }
      string itr=mpp[s[idx]-'0'];
      int n=itr.size();
      for(int i=0;i<n;i++){
        gen(s,idx+1,ds+itr[i],ans,mpp);
      }
    }
};