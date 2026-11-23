class ProductOfNumbers {
private:
    vector<int> prefixProducts;

public:
    ProductOfNumbers() {
        prefixProducts.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts.clear();
            prefixProducts.push_back(1);
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= (int)prefixProducts.size()) {
            return 0;
        }
        
        return prefixProducts.back() / prefixProducts[prefixProducts.size() - 1 - k];
    }
};