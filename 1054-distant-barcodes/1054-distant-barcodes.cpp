class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;
        for(int num:barcodes){
            freq[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto &it:freq){
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while(pq.size()>=2){
            auto [a1, b1]=pq.top();
            pq.pop();
            auto [a2, b2]=pq.top();
            pq.pop();

            ans.push_back(b1);
            ans.push_back(b2);
            if(--a1){
                pq.push({a1, b1});
            }
            if(--a2){
                pq.push({a2, b2});
            }
        }
        if(!pq.empty())
            ans.push_back(pq.top().second);

        return ans;
    }
};