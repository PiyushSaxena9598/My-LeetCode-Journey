class Solution {
public:
    int GCD(int a, int b){
        if(b==0)
        return a;

        return GCD(b, a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int k=n;
        int sum1=0;
        int sum2=0;
        while(k--){
            sum1+=2;
        }
        k=n;
        while(k--){
            sum2+=1;
        }
        return GCD(sum1, sum2);
    }
};