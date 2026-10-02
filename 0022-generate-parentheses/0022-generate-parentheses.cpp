class Solution {
public:
    void fn(int left, int right, string temp, vector<string>& ans, int n){
        if(left+right==2*n){
            ans.push_back(temp);
            return;
        }
        if(left<n){
            temp.push_back('(');
            fn(left+1, right, temp, ans, n);
            temp.pop_back();
        }
        if(right<left){
            temp.push_back(')');
            fn(left, right+1, temp, ans, n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        fn(0, 0, temp, ans, n);
        return ans;
    }
};