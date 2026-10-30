class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }

        vector<vector<long long>> dist(
            n, vector<long long>(k+1, LLONG_MAX)
        );

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        // {distance, node, consecutive count}
        pq.push({0, 0, 1});
        dist[0][1] = 0;

        while(!pq.empty()) {
            auto [sum, node, count] = pq.top();
            pq.pop();

            if(sum > dist[node][count]) continue;

            if(node == n-1) {
                return (int)sum;
            }

            for(auto it : adj[node]) {
                int next = it.first;
                int w = it.second;

                int newCount = 1;

                if(labels[node] == labels[next]) {
                    newCount = count + 1;
                }

                if(newCount > k) continue;

                if(sum + w < dist[next][newCount]) {
                    dist[next][newCount] = sum + w;

                    pq.push({
                        sum + w,
                        next,
                        newCount
                    });
                }
            }
        }

        return -1;
    }
};