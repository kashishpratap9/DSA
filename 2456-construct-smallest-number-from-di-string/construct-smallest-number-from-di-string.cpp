class Solution {
public:

// void pattern1(int i,  string&result,vector<bool>&visited ,string&pattern){
//     int n=pattern.size();
//     if(result.size()==pattern.size()|| i==n+1){
//         cout<<result<<endl;
       
//         return ;
//     }


//     for( int j=1;j<=9;j++){
      
//         if(!visited[j]){
//             result.push_back(j+'0');
//             visited[j]=true;
//             // pattern1(i+1, result, ans, visited, pattern);
//             if(pattern[i]=='I' && result[i-1]-'0' <j||  pattern[i]=='D' &&  result[i-1]-'0' >j){
//                    pattern1(i+1, result,  visited, pattern);   
//             }

       
              

          
//            result.pop_back();
//           visited[j]= false;
            
//         }
//     }

    
// }
    string smallestNumber(string pattern) {
       string result = "";
    stack<int> st;
    
    for (int i = 0; i <= pattern.size(); i++) {
        st.push(i + 1);
        
        if (i == pattern.size() || pattern[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    
    return result;
    }
};