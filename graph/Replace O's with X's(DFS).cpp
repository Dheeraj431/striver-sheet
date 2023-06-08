// User function Template for C++
//Problem Link : https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
class Solution{
public:
    void dfs(int r, int c, vector<vector<char>>&vis, vector<vector<char>>mat){
        int n=mat.size();
        int m=mat[0].size();
        vis[r][c]='1';
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        for(int k=0; k<4; k++){
            int nr=r+dx[k];
            int nc=c+dy[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]=='0' && mat[nr][nc]=='O'){
                dfs(nr,nc,vis,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>>vis(n,vector<char>(m,'0'));
        //rows
        for(int i=0; i<m; i++){
            if(vis[0][i]=='0' && mat[0][i]=='O'){
                dfs(0,i,vis,mat);
            }
            
            if(vis[n-1][i]=='0' && mat[n-1][i]=='O'){
                dfs(n-1,i,vis,mat);
            }
            
        }
        
        for(int i=0; i<n; i++){
            if(vis[i][0]=='0' && mat[i][0]=='O'){
                dfs(i,0,vis,mat);    
            }
            
            if(vis[i][m-1]=='0' && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat);    
            }
            
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == '0' && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
            
        }
        return mat;
        
    }
};
