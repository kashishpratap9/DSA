class Solution {
public:

// void Tiles(int i,string ans, string&s,unordered_set<string>&st){
//     if(i>=s.size()){
//         if(ans!=""){
//         st.insert(ans);
//         }
//         return ;
//     }
// ans.push_back(s[i]);
//     Tiles(i+1,ans, s, st);
//   ans.pop_back();
//     Tiles(i+1,ans, s, st);

  
// }
// bool cantake(char ch , unordered_map<char, int>&mp){
   
//     return mp[ch]>0;
// }

void Tiles(int&count, string&s, unordered_map<char, int>&mp){

   for(auto&[ch, cn]: mp){
    if( cn>0){
        
        // s1.push_back(ch);
        count++;
        mp[ch]--;
        Tiles(count, s, mp);
        // s1.pop_back();
        mp[ch]++;
    }
   }



}


    int numTilePossibilities(string tiles) {

        unordered_map<char, int>mp;
        unordered_set<string>st;
         for( int i=0;i<tiles.size();i++){
            mp[tiles[i]]++;
         }
         int count=0;

        Tiles(count, tiles, mp);
        return count;
    }



};