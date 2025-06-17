class Solution {
public:
    string palindrome(int l,int r,string s){
      if(s.size()<=1){
        return s;
      }
      
      while(l>=0 && r<s.size() && s[l]==s[r]){
        l--;
        r++;
      }
      return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
      int n=s.size();
      string maxm="";
      for(int i=0;i<n;i++){
        string a=palindrome(i,i,s);
        string b=palindrome(i,i+1,s);
        if(a.size()>maxm.size()){
          maxm=a;
        }
        if(b.size()>maxm.size()){
          maxm=b;
        }
      }
      return maxm;  
    }
};