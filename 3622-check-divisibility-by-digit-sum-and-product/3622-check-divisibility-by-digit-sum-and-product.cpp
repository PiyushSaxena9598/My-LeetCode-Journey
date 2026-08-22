class Solution {
public:
    int find1(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int find2(int n){
        int prod=1;
        while(n){
            prod*=n%10;
            n/=10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        int sum=find1(n);
        int prod=find2(n);
        int total=sum+prod;
        if(n%total==0) return true;
        return false;
    }
};