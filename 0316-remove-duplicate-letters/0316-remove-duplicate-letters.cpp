class Solution {
public:
    string removeDuplicateLetters(string s) {
    int n=s.size();
    map<char,int>mpp1,mpp2;
    stack<char>st;
    for(int i=0;i<n;i++){
    mpp1[s[i]]=i;
    }
    for(char c='a';c<='z';c++){
        mpp2[c]=0;
    }
    for(int i=0;i<n;i++){
        if(mpp2[s[i]]==1) continue;
        while(!st.empty() && st.top()>s[i] && i<mpp1[st.top()]){
            mpp2[st.top()]=0;
            st.pop();
        }
        st.push(s[i]);
        mpp2[s[i]]=1;
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};