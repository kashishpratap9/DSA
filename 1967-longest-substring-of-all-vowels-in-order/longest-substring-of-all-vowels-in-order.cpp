class Solution {
public:
    int longestBeautifulSubstring(string word) {
        unordered_map<char, int>mp;
        stack<char>st;
         int l=0;
          int r=0;

          int maxlen=0;
          int count=0;
          while(r<word.size()){
    //         unordered_map<char, int> mp;
    // stack<char> st;
    // int l = 0, r = 0;
    // int maxlen = 0;

    // while (r < word.size()) {
    //     // Push current character to stack and map
    //     if (st.empty() || st.top() <= word[r]) {
    //         mp[word[r]]++;
    //         st.push(word[r]);
    //     }

    //     // If the character violates the order, adjust window
    //     while (!st.empty() && st.top() > word[r]) {
    //         mp[word[l]]--;
    //         if (mp[word[l]] == 0) {
    //             mp.erase(word[l]);
    //         }
    //         st.pop();
    //         l++;
    //     }

    //     // Check if we have all 5 vowels in order and count the length
    //     if (mp.size() == 5) {
    //         maxlen = max(maxlen, r - l + 1);
    //     }

    //     // Move right pointer
    //     r++;


          if (count == 0 || (word[r] > word[r-1])) {
            // If it's the first character or it's larger than the previous one, it fits
            count++;
        } else if (word[r] < word[r-1]) {
            // If the character is smaller than the previous one, reset the count and adjust the window
            while (l < r) {
                // if (word[l] == word[r-1]) {
                //     l++;
                //     break;
                // }
                l++;
            }
            count = 1;  // Restart count for the new character
        }

        // If we've seen all 5 vowels in order
        if (count == 5) {
            maxlen = max(maxlen, r - l + 1);
        }

        r++;
    

          }

          return maxlen;
        
    }
};