class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int len=INT_MIN;
    int n=s.size(),a=0;
    map<char,int>mpp;
    for(int i=0;i<n;i++){
        while(mpp.find(s[i])!=mpp.end()){
            mpp[s[a]]--;
            if(mpp[s[a]]==0) mpp.erase(s[a]);
            a++;
        }
        mpp[s[i]]++;
        len=max(len,i-a+1);
    }
    return len==INT_MIN?0:len;    
    }
};