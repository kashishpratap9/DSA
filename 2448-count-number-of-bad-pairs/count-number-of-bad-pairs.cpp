class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
         long long n = nums.size();
    long long totalPairs = (n * (n - 1)) / 2;  // Total possible pairs
    
    unordered_map<int, long long> freq;
    long long goodPairs = 0;

    for (int i = 0; i < n; i++) {
        int key = nums[i] - i;
        goodPairs += freq[key];  // Count how many times this value has appeared
        freq[key]++;  // Store the occurrence
    }

    return totalPairs - goodPairs; 
    }
};