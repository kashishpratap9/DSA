class Solution {
public:
// int FibSeq( int i, int& prev1, int&prev2, vector<int>&arr, vector<vector<vector<int>>>&dp){
//     if(i>=arr.size()){
//         return 0;
//     }

//     if( dp[i][prev1][prev2]!=-1){
//         return dp[i][prev1][prev2];

//     }
//     int inc=0;
//     if(arr[prev1]+ arr[prev2]== arr[i]){
//         //in this casen we will include
//         //in case of include i will do 1+
//         inc=1+ FibSeq(i+1,prev2, i, arr, dp);
//     }

//     //other case we will exclude
//     int exc=FibSeq(i+1, prev1,prev2, arr, dp);

//     //at last we have to return the max of ( inc, exc)
//     return dp[i][prev1][prev2]=max( inc, exc);


// }
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n= arr.size();
//        int max_len = 0;
// vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1 , -1)));
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             int len = 2 + FibSeq(j + 1, i,j, arr, dp);
//             max_len = max(max_len, len);
//         }
//     }

//     return max_len >= 3 ? max_len : 0;


        
//     }
 int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // Store array elements in set for O(1) lookup
        unordered_set<int> numSet(arr.begin(), arr.end());

        int maxLen = 0;
        // Try all possible first two numbers of sequence
        for (int start = 0; start < n; ++start) {
            for (int next = start + 1; next < n; ++next) {
                // Start with first two numbers
                int prev = arr[next];
                int curr = arr[start] + arr[next];
                int len = 2;

                // Keep finding next Fibonacci number
                while (numSet.find(curr) != numSet.end()) {
                    // Update values for next iteration
                    int temp = curr;
                    curr += prev;
                    prev = temp;
                    maxLen = max(maxLen, ++len);
                }
            }
        }

        return maxLen;
    }
};