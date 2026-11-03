class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v, -1);
        queue<int> q;
        
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<graph[node].size();j++){
                        if(color[graph[node][j]]==-1)
                        {
                            color[graph[node][j]]=(color[node]+1)%2;
                            q.push(graph[node][j]);
                        }
                        else
                        {
                            if(color[node]==color[graph[node][j]]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};