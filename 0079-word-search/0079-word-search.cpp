class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    int m=board.size(),n=board[0].size();
    vector<vector<int>>hash(m,vector<int>(n,1));
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(solve(i,j,0,m,n,board,word,hash)) return true;
      }
    }
    return false;    
    }
    bool solve(int i,int j,int idx,int m,int n,vector<vector<char>>& board,string word,vector<vector<int>>&hash){
      if(idx>=word.size()) return true;
      if(i>=m || j>=n || i<0 || j<0 || word[idx]!=board[i][j] || hash[i][j]==0) return false;
      hash[i][j]=0;
      bool a=solve(i,j-1,idx+1,m,n,board,word,hash); //left
      if(a==true) return true;
      bool b=solve(i,j+1,idx+1,m,n,board,word,hash); //right
      if(b==true) return true;
      bool c=solve(i-1,j,idx+1,m,n,board,word,hash); //up
      if(c==true) return true;
      bool d=solve(i+1,j,idx+1,m,n,board,word,hash); //down
      if(d==true) return true;
      hash[i][j]=1;

      return false;
    }
};