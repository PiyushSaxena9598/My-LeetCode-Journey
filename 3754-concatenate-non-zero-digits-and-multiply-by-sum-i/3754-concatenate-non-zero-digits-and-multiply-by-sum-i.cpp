class Solution {
public:
    long long sumAndMultiply(int n) {
        long long digit=0;
        long long sum=0;
        while(n){
            long long last=n%10;
            if(last!=0){
                digit=(digit*10)+last;
                sum+=last;
            }
            n/=10;
        }
        long long rev=0;
        n=digit;
        while(n){
            long long last=n%10;
            rev=(rev*10)+last;
            n/=10;
        }
        digit=rev;
        return digit*sum;
    }
};