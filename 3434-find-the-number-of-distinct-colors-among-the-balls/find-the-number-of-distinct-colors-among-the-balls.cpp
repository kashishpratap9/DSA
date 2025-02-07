class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

    // vector<int>limits;
    // for( int i=0;i<=limit;i++){
    //     limits.push_back(i);      
    // }
    vector<int>result;
    unordered_map<int, int>mp;
     unordered_map<int, int> color_count;
    
  set<int>st;
        
            for(auto&u: queries){
                int ball= u[0];
                int color=u[1];
            
                if(mp.find(ball)==mp.end()){
                    mp[ball]=color;
                    color_count[color]++;
                    st.insert(color);
                    // st.insert(ball);
                }else {
                    if(mp[ball] != color){
                     color_count[mp[ball]]--;
                     if(color_count[mp[ball]]==0){
                             st.erase(mp[ball]);
                     }
                       
                        mp[ball]= color;
                        color_count[mp[ball]]++;
                        st.insert(color);
                    }
                }
             
                int size= st.size();
                result.push_back(size);

            }

        return result;
        
        
    }
};