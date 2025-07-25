class Solution {
public:
    bool isVowel(char c){
      return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    long long count(string s,int k){
      long long n=s.size();
      long long cnt=0,consonent=0,a=0;
      map<long long,long long>mpp;
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
    long long countOfSubstrings(string s, int k) {
      long long n=s.size();
      return count(s,k)-count(s,k+1);
    }

};