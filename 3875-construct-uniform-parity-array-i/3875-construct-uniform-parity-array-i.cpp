class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0;
        int even=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(odd==nums1.size() || even==nums1.size()){
            return true;
        }
        if(odd>=1 && even>=1){
            return true;
        }
        if(odd>=2){
            return true;
        }
        return false;
    }
};