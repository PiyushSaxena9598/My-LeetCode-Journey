class Solution {
public:
    int Digit(int a, int b, int c){
        return a*100+b*10+c;
    }
    int check(int n){
        int count=0;
        while(n){
            count++;
            n/=10;
        }
        return count;
    }
    int totalNumbers(vector<int>& digits) {
        set<int> st;
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits.size();j++){
                for(int k=0;k<digits.size();k++){
                    if(i!=j && i!=k && j!=k){
                        int digit=Digit(digits[i], digits[j], digits[k]);
                        if(digit%2==0 && check(digit)==3)
                        st.insert(digit);
                    }
                }
            }
        }
        return st.size();
    }
};