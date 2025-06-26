class Solution {
public:
    long long validSubstringCount(string s, string target) {
    long long n=s.size();
    vector<vector<long long>>pre(n+1,vector<long long>(26));
    for(long long i=0;i<n;i++){
      pre[i+1]=pre[i];
      pre[i+1][s[i]-'a']++;
    }
    vector<int>hash(26,0);
    for(auto it:target) hash[it-'a']++;

    auto isCnt = [&] (int start,int end,int idx){
      return pre[end+1][idx] - pre[start][idx];
    };

    auto findEnd= [&] (long long start){
      long long s=start , e = n-1, ans=n;
      while(s<=e){
        long long mid=s+(e-s)/2;
        bool isGood=true;
        for(int i=0;i<26;i++){
          if(isCnt(start,mid,i)<hash[i]){
            isGood=false;
            break;
          }
        }
        if(isGood) e=mid-1,ans=mid;
        else s=mid+1;
      }
      return ans;
    };
    long long cnt=0;
    for(int i=0;i<n;i++){
      int e = findEnd(i);
      cnt+=(n-e);
    }
    return cnt;   
    }
};