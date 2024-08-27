class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n=s.size();unordered_map<char,int>mpp;
int a=0;int mlen=0;
for(int i=0;i<n;i++){
	if(mpp[s[i]]==0){
		mpp[s[i]]++;
	}
	else{
	while(mpp[s[i]]!=0){
		mpp[s[a]]--;
		if(mpp[s[a]]==0) mpp.erase(s[a]);
		a++;
	}
	mpp[s[i]]++;
}
	mlen=max(mlen,i-a+1);
}
return mlen;    
    }
};