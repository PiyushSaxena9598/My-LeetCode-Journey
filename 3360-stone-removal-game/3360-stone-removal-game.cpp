class Solution {
public:
    bool canAliceWin(int n) {
        int a=10;
        bool alice=true;
        while(true){
            if(alice){
                if(n<a) return false;
                n-=a;
                a--;
                alice=false;
            }
            else{
                if(n<a){
                    return true;
                }
                n-=a;
                a--;
                alice=true;
            }
        }
        return true;
    }
};