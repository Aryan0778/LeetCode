class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    vector<int>hash(26,0);
    vector<int>temp(26,0);
    vector<int>ans;
    int a=0,n=s.size();
    for(int i=0;i<p.size();i++) hash[p[i]-'a']++;
    for(int i=0;i<n;i++){
        while(i-a+1>p.size()){
            temp[s[a]-'a']--;
            a++;
        }
        temp[s[i]-'a']++;
        if(hash==temp) ans.push_back(a);
        
    }
    return ans;
    }
};