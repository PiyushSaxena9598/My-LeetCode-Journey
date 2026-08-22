class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> brr(26, 0);
        vector<int> crr(26, 0);
        for(int i=0;i<s.size();i++){
            brr[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            crr[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(brr[i]!=crr[i])
            return false;
        }
        return true;
    }
};