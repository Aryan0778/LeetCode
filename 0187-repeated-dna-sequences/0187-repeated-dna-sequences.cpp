class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    int n=s.size();
    set<string>unq;
    map<string,int>mpp;
    vector<string>ans;
    for(int i=0;i<n-9;i++){
        string k=s.substr(i,10);
        if(mpp.find(k)!=mpp.end()){
            unq.insert(k);
        }
        else{
            mpp[k]++;
        }
    }
    for(auto it:mpp) cout<<it.first<<" "<<it.second<<endl;
    for(auto it:unq) ans.push_back(it);
    return ans;    
    }
};