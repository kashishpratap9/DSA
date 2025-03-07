class Solution {
public:

bool isPrime(int n){

    if(n<=1){
        return false;
    }
    for( int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }    
    }
    return true;
}
    bool isUgly(int n) {

        if( n<=0){
             return false;
        }
        // vector<int>factor;
        // for(int i=2;i<=n/2;i++){
        //     if(n%i==0){
        //         cout<<i;
        //         factor.push_back(i);
        //     }
        // }
        // for( int i=0;i<factor.size();i++){
        //    if( isPrime(factor[i])){
        //         if(factor[i]!=2 && factor[i]!=3 && factor[i]!=5){
        //                 return false;
        //         }
        //    }
         
        // }

        while( n!=1){
            if(n%2==0){
                n/=2;
            }else if(n%3==0){
                n/=3;
            }else if( n%5==0){
                n/=5;
            }else{
                return false;
            }
        }
        return true;
        
    }
};