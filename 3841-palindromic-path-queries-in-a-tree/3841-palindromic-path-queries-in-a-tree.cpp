class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, sz;
    vector<int> seg;
    int timer;

    // Build parent, depth, subtree size and heavy child
    void dfs1(int node, int par) {
        parent[node] = par;
        sz[node] = 1;

        int maxi = 0;

        for(auto it : adj[node]) {
            if(it == par) continue;

            depth[it] = depth[node] + 1;
            dfs1(it, node);

            sz[node] += sz[it];

            if(sz[it] > maxi) {
                maxi = sz[it];
                heavy[node] = it;
            }
        }
    }

    // Assign positions to nodes
    void dfs2(int node, int h) {
        head[node] = h;
        pos[node] = timer++;

        if(heavy[node] != -1) {
            dfs2(heavy[node], h);
        }

        for(auto it : adj[node]) {
            if(it == parent[node] || it == heavy[node])
                continue;

            dfs2(it, it);
        }
    }

    // Build segment tree
    void build(int idx, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);

        seg[idx] = seg[2*idx+1] ^ seg[2*idx+2];
    }

    // Update one node
    void update(int idx, int low, int high, int p, int val) {
        if(low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if(p <= mid)
            update(2*idx+1, low, mid, p, val);
        else
            update(2*idx+2, mid+1, high, p, val);

        seg[idx] = seg[2*idx+1] ^ seg[2*idx+2];
    }

    // XOR query over a segment
    int query(int idx, int low, int high, int l, int r) {
        if(high < l || low > r)
            return 0;

        if(low >= l && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;

        return query(2*idx+1, low, mid, l, r)
             ^ query(2*idx+2, mid+1, high, l, r);
    }

    // XOR of characters on path u -> v
    int pathQuery(int u, int v, int n) {
        int mask = 0;

        while(head[u] != head[v]) {
            if(depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(0, 0, n-1, pos[head[u]], pos[u]);

            u = parent[head[u]];
        }

        if(depth[u] > depth[v])
            swap(u, v);

        mask ^= query(0, 0, n-1, pos[u], pos[v]);

        return mask;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {

        adj.resize(n);
        parent.resize(n);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        sz.resize(n);
        seg.resize(4*n);
        timer = 0;

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(0, -1);
        dfs2(0, 0);

        vector<int> arr(n);

        for(int i=0; i<n; i++) {
            arr[pos[i]] = 1 << (s[i]-'a');
        }

        build(0, 0, n-1, arr);

        vector<bool> ans;

        for(int i=0; i<queries.size(); i++) {
            stringstream ss(queries[i]);

            string type;
            ss >> type;

            if(type == "update") {
                int u;
                char ch;
                ss >> u >> ch;

                s[u] = ch;

                update(0, 0, n-1, pos[u], 1 << (ch-'a'));
            }
            else {
                int u, v;
                ss >> u >> v;

                int mask = pathQuery(u, v, n);

                ans.push_back((mask & (mask-1)) == 0);
            }
        }

        return ans;
    }
};