class NumberContainers {
public:
map<int, int>mp;
set<pair<int, int>>st;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.find(index)!= mp.end()){
            st.erase({mp[index], index});
            // mp.erase(index);
        }

        mp[index]=number;
        st.insert({number, index});
        
       
    }
    
    int find(int number) {
       
       auto it = st.lower_bound({number, 0}); // Find the first occurrence of 'number'
        cout<<it->first<<" "<<it->second;
        if (it != st.end() && it->first == number) {
            return it->second;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */