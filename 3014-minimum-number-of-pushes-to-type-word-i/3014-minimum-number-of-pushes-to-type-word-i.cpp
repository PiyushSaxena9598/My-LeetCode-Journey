class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<8) return n;
        int ans=0;
        int i=1;
        
        while (n){
            if(n>=8){
                ans+=8*i;
                n-=8;
            } else{
                ans+=n*i;
                n=0;
            }
            i++;
        }
        return ans;
    }
};