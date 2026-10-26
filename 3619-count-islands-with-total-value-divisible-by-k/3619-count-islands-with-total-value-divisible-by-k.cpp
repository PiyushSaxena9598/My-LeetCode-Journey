class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    visited[i][j]=1;
                    long long sum=0;
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        sum+=grid[x][y];
                        for(int k=0;k<4;k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]>0 && !visited[nx][ny]){
                                q.push({nx, ny});
                                visited[nx][ny]=1;
                            }
                        }
                    }
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};