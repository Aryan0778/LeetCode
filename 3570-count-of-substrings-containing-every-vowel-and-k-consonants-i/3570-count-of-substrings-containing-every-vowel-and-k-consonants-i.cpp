class Solution {
public:
    bool isVowel(char c){
      return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int count(string s,int k){
      int n=s.size();
      int cnt=0,consonent=0,a=0;
      map<int,int>mpp;
      for(int i=0;i<n;i++){
        if(isVowel(s[i])){
          mpp[s[i]]++;
        }
        else{
          consonent++;
        }
        while(mpp.size()==5 && consonent>=k){
          cnt+=(n-i);
          
          if(isVowel(s[a])){
            mpp[s[a]]--;
            if(mpp[s[a]]==0)mpp.erase(s[a]);
          } 
          else consonent--;
          a++;
        }
      }
      return cnt;
    }
    int countOfSubstrings(string s, int k) {
      int n=s.size();
      return count(s,k)-count(s,k+1);
    }

};