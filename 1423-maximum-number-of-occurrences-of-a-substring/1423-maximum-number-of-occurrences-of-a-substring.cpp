class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<char,int>hash;
        map<string,int>freq;
        int n = s.size(),a=0,ans=0;
        string str="";
        for(int i=0;i<n;i++){
          hash[s[i]]++;
          str+=s[i];
          if(a<n && i-a+1>minSize){
            hash[s[a]]--;
            if(hash[s[a]]==0) hash.erase(s[a]);
            a++;
            str.erase(str.begin());
          }
          if(i-a+1==minSize && hash.size()<=maxLetters){
            freq[str]++;
          }
        }
        for(auto it:freq)ans=max(ans,it.second);
        return ans;
    }
};