class ProductOfNumbers {
public:
    vector<long> v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        long n = v.size();
        long last_index = n-1;
        vector<long> temp;
        while(k--) {
            temp.push_back(v[last_index]);
            last_index--;
        }
        long product = 1;
        for(long el: temp) {
            product *= el;
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