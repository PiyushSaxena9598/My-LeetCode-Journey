
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        vector<int> brr(arr.size(), 0);
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (arr[i] == arr[j]) {
                    brr[i]++;
                }
            }
        }
        vector<string> temp1;

        for (int i = 0; i < arr.size(); i++) {
            if (brr[i] == 1) {
                temp1.push_back(arr[i]);
            }
        }

        if (temp1.size() < k) {
            return "";
        }

        return temp1[k - 1];
    }
};

