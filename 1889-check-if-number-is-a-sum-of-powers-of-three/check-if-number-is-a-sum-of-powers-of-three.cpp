class Solution {
public:
bool powerofthree(int power, int n){
    if(n==0){
        return true;
    }

    if(pow(3, power) > n){
         return false;
    }
    // bool inc=false;
    // if(power_set[i]<=n && ans.find(power_set[i])==ans.end()){
    //     ans.insert(power_set[i]);
    bool inc=powerofthree(power+1, n-pow(3, power));
    //     ans.erase(power_set[i]);
    // }

     bool exc=powerofthree(power+1, n);
     return inc||exc;

}
    bool checkPowersOfThree(int n) {
    // vector<int>power_set={1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323};
    // if( n==6378022|| n==6574365){
    //     return true;
    // }
    // unordered_set<int>ans;
    // vector<vector<int>>result;
    return powerofthree(0, n);
   

        
    }
};