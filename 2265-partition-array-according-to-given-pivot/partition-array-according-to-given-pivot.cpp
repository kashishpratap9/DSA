class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>temp(nums.begin(), nums.end());
        vector<int>left;
        vector<int>p;
        vector<int>right;
        for(int i=0;i<nums.size();i++){
            if( nums[i]< pivot)
                left.push_back( nums[i]);
            else if(nums[i]==pivot){
                p.push_back( nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }
        int index=0;
        
        for( int i=0;i<left.size();i++){
             nums[index++]=left[i];
        }
        // cout<<endl;

        for( int i=0;i<p.size();i++){
            nums[index++]=p[i];
        }
          for( int i=0;i<right.size();i++){
            nums[index++]=right[i];
        }

        return nums;
       


        
    }
};