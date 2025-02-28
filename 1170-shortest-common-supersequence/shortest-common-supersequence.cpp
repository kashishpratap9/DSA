class Solution {
public:
int scs(int i, int j, string&s1, string&s2){
    if( i==s1.length()){
        return s2.length()-j;
    }
    if( j==s2.length()){
        return s1.length()-i;
    }

    if(s1[i]==s2[j]){
        return 1 + scs(i+1, j+1, s1, s2);

    }

    return min(1+ scs(i+1, j, s1, s2) , 1+ scs(i, j+1, s1, s2));

}


    string shortestCommonSupersequence(string str1, string str2) {
        
         int n= str1.size();
        int  m= str2.size();

         vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
         dp[0][0]=0;
         for( int i=1;i<=n;i++){
            dp[i][0]=i;
         }
         for( int j=1;j<=m;j++){
            dp[0][j]=j;
         }

         for( int i=1;i<=n;i++){
             for( int j=1;j<=m;j++){
                if( str1[i-1]==str2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }else{
                    dp[i][j]= 1+ min( dp[i-1][j], dp[i][j-1]);
                }
             }
         }
         int i=n;
         int j=m;
         string ans="";
         while(i>0 && j>0){
             if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
             }else if( dp[i-1][j] < dp[i][j-1]){
                     ans.push_back(str1[i-1]);
                    i--;
                }else{
                    ans.push_back(str2[j-1]);
                     j--;

                }
             
         }


         while(i>0){
            ans.push_back(str1[i-1]);
             i--;
         }

          while(j>0){
            ans.push_back(str2[j-1]);
             j--;
         }

         reverse(ans.begin(), ans.end());


         return ans;

        
    }
};