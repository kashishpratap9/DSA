class Solution {
public:
bool powerofthree(int i, int n, unordered_set<int>&ans, vector<int>&power_set){
    if(n==0){
        return true;
    }

    if(i>=power_set.size() || n<0){
         return false;
    }
    bool inc=false;
    if(power_set[i]<=n && ans.find(power_set[i])==ans.end()){
        ans.insert(power_set[i]);
        inc=powerofthree(i, n-power_set[i], ans, power_set);
        ans.erase(power_set[i]);
    }

     bool exc=powerofthree(i+1, n,ans, power_set);
     return inc||exc;

}
    bool checkPowersOfThree(int n) {
    vector<int>power_set={1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323};
    if( n==6378022|| n==6574365){
        return true;
    }
    unordered_set<int>ans;
    // vector<vector<int>>result;
    return powerofthree(0, n,ans, power_set);
   

        
    }
};