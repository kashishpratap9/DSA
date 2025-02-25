class Solution {
public:


int isPossible(int indx,vector<int>& gas, vector<int>& cost){  
        int n= gas.size(); 
                int cir=indx;
                int value= gas[indx]; 
                cout<<value;
                indx=(indx+1)%n;       
                while(indx!=cir){
                     value -= cost[(indx - 1 + n) % n];  
                     if(  value<0){
                         return -1;
                     }

                    indx=(indx+1)%n;
             
                }
   

    return cir;

            
        
}
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     unordered_set<int>st;
    //    int n= gas.size();
    //     int i=0;
    //     int indx=-1;
    //    for(int i=0;i<gas.size();i++){
    //         if( gas[i]-cost[i]>=0){
    //             int ans = isPossible(i, gas, cost);
    //             if( ans !=-1){
    //             return ans;
    //             }
    //         }
    //      }

    //   return -1;

    int total_gas = 0, total_cost = 0;
    int tank = 0, start_index = 0;

    for (int i = 0; i < gas.size(); i++) {
        total_gas += gas[i];
        total_cost += cost[i];
        tank += gas[i] - cost[i];

        // If at any point tank goes negative, reset start index
        if (tank < 0) {
            start_index = i + 1;  // Next station might be the valid start
            tank = 0;  // Reset tank
        }
    }

    // If total gas is less than total cost, it's impossible to complete the circuit
    return (total_gas < total_cost) ? -1 : start_index;


        
    }
};