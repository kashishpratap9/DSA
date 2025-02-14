class ProductOfNumbers {
public:
vector<int>ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
        
    }
    
    int getProduct(int k) {
        long long  product=1;
        int i=ans.size()-1;
       while( k!=0){
        product*=ans[i];
        i--;
        k--;

       }

       return product;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */