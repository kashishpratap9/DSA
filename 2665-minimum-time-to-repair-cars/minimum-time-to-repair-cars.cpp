class Solution {
public:
bool isPossible(vector<int>&ranks, int cars, long long mid){
    long long  cn=0;
    for( int i=0;i<ranks.size();i++){
             cn+=sqrt(mid/ranks[i]);
             if( cn>=cars){
                return true;
             }
    }

    return false;
}
    long long repairCars(vector<int>& ranks, int cars) {
      long long mini = LLONG_MAX;
long long maxi = LLONG_MIN;
for (int i = 0; i < ranks.size(); i++) {
    mini = min(mini, (long long)ranks[i]);  // Explicit typecast to long long
    maxi = max(maxi, (long long)ranks[i]);  
}

long long l = mini;
long long r = maxi * (1LL * cars * cars); // Ensure long long multiplication
long long ans = -1;

while (l <= r) {
    long long mid = l + (r - l) / 2;
    if (isPossible(ranks, cars, mid)) {
        ans = mid;
        r = mid - 1;
    } else {
        l = mid + 1;
    }
}
return ans;

        
    }
};