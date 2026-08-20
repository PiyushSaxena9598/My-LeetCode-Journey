class Solution {
public:
    bool validDigit(int n, int x) {
        if(n==0) return false;
        vector<int> v;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(), v.end());
        if(v[0]==x) return false;
        int count=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==x) count++;
        }
        if(count<1) return false;
        return true;
    }
};