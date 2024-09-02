class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int len=INT_MIN;
    int n=s.size(),a=0;
    set<char>st;
    for(int i=0;i<n;i++){
        while(st.find(s[i])!=st.end()){
            st.erase(s[a]);
            a++;
        }
        st.insert(s[i]);
        len=max(len,(int)st.size());
    }
    return len==INT_MIN?0:len;    
    }
};