class Solution {
public:
    int deltaX[4]={-1, 1, 0, 0};
    int deltaY[4]={0, 0, 1, -1};
    int n, m;
    bool valid(int r, int c){
        return r>=0 && r<n && c>=0 && c<m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        visited[0][0]=0;
        q.push(make_pair(0, 0));
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow=r+deltaX[i];
                int newCol=c+deltaY[i];
                if(valid(newRow, newCol)){
                    int diff=abs(heights[r][c]-heights[newRow][newCol]);
                    int newEffort=max(visited[r][c], diff);
                    if(newEffort < visited[newRow][newCol]){
                        visited[newRow][newCol]=newEffort;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        return visited[n-1][m-1];
    }
};