class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        // Sort the array
        sort(arr.begin(), arr.end());

        // Store frequency of each unique number
        vector<int> freq;

        int count = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }

        // Add frequency of last element
        freq.push_back(count);

        // Number of unique elements
        int unique = freq.size();

        // Sort frequencies
        sort(freq.begin(), freq.end());

        // Remove elements with smallest frequencies
        for (int f : freq) {
            if (k >= f) {
                k -= f;
                unique--;
            } else {
                break;
            }
        }

        return unique;
    }
};