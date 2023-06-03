// User function Template for C++

//Problem Link : https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

class Solution {
  public:
    
    int shortestDistance(int n, int m, vector<vector<int>>& arr, int x, int y) {
    int moveCount = 0, nodesInNextLayer = 0, nodesLeft = 1;
    bool reachedEnd = false;
    if(arr[x][y]==0 || arr[0][0]==0){
        return -1;
    }
    arr[x][y] = -1;
    queue<int> rc;
    queue<int> cc;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    rc.push(0);
    cc.push(0);
    visited[0][0] = true;
    while (!rc.empty() && !cc.empty()) {
        int r = rc.front();
        int c = cc.front();
        rc.pop();
        cc.pop();
        if (arr[r][c] == -1) {
            reachedEnd = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= n || nc >= m || nr < 0 || nc < 0) {
                continue;
            }
            if (visited[nr][nc] || arr[nr][nc] == 0) {
                continue;
            }
            rc.push(nr);
            cc.push(nc);
            visited[nr][nc] = true;
            nodesInNextLayer++;
        }
        nodesLeft--;
        if (nodesLeft == 0) {
            nodesLeft = nodesInNextLayer;
            nodesInNextLayer = 0;
            moveCount++;
        }
        
    }
    if (reachedEnd) {
            return moveCount;
    }
    return -1;
}


};
