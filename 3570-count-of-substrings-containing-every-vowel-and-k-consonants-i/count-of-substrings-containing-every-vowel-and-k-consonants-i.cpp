class Solution {
public:
    int countOfSubstrings(string word, int k) {
         
        int l=0;
        int r=0;
        int countc=0;
    int count=0;
        vector<int>indx(word.size(), 0);
        unordered_map<char, int>mp;

        stack<int>st;
      
        for(int i=word.size()-1;i>=0;i--){

             if( st.empty()){
            indx[i]=word.size();
            }
            else if(!st.empty()){
                indx[i]=st.top();
                // st.pop();

            }
             if( word[i]!='a' &&word[i]!= 'e' && word[i]!='i' && word[i]!='o' && word[i]!='u'){
                    st.push(i);
             }
            
        }

        while(r<word.size()){
            if(word[r]=='a'|| word[r]=='e'|| word[r]=='i'|| word[r]=='o'||word[r]=='u'){
                mp[word[r]]++;
            }else{
                countc++;
            }

            while( countc>k){
                if(word[l]!='a' &&word[l]!= 'e' && word[l]!='i' && word[l]!='o' && word[l]!='u'){
                    countc--;
                }else{
                    mp[word[l]]--;
                    if( mp[word[l]]==0){
                         mp.erase(word[l]);
                    }
                }
            l++;
            }


            while( mp.size()==5 && countc==k){
                count+=(indx[r]-r);
                 if(word[l]!='a' &&word[l]!= 'e' && word[l]!='i' && word[l]!='o' && word[l]!='u'){
                    countc--;
                }else{
                    mp[word[l]]--;
                    if( mp[word[l]]==0){
                         mp.erase(word[l]);
                    }
                }
                 l++;
            }

            r++;

        }

         return count;
        
    }
};