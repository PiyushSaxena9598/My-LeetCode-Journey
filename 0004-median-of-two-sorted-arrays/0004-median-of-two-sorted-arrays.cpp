class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> temp(n1+n2);
        int left=0;
        int right=0;
        int idx=0;
        while(left<n1 && right<n2){
            if(nums1[left]<=nums2[right]){
                temp[idx++]=nums1[left++];
            }
            else{
                temp[idx++]=nums2[right++];
            }
        }
        while(left<n1){
            temp[idx++]=nums1[left++];
        }
        while(right<n2){
            temp[idx++]=nums2[right++];
        }
        int n=temp.size();
        if(n%2!=0){
            double ans=temp[n/2]*1.0;
            return ans;
        }
        double ans=(temp[n/2]+temp[n/2-1])/2.0;
        return ans;
    }
};