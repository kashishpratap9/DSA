class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

    for (char ch : s) {
        if (isdigit(ch)) {
            if (!st.empty()) {
                st.pop(); // Remove the closest non-digit character
            }
        } else {
            st.push(ch); // Push non-digit characters onto the stack
        }
    }

    // Construct the final string from the stack
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    // Reverse the string since we built it from the stack
    reverse(result.begin(), result.end());
    return result;
        
    }
};