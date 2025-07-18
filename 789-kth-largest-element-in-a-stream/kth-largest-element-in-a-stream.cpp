class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
  int K;

    KthLargest(int k, vector<int>& nums){
        K=k;
        int i;
       for(i=0;i<nums.size();i++){
          if(pq.size()<K){
            pq.push( nums[i]);
          }else{
            break;
          }
       }

      
        while( i<nums.size()){
            if(!pq.empty()&&nums[i]>pq.top()){
                pq.pop();
            pq.push(nums[i]);

            }
            i++;
        
       }
        
        
    }
    
    int add(int val) {

        if(!pq.empty()&& val> pq.top()&& pq.size()==K){
            pq.pop();
            pq.push(val);
        }

         else if(pq.size()<K){ 
            pq.push(val);  
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */