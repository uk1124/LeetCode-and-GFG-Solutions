class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() and price >= st.top().first) {
            span += st.top().second;    // Accumulate the count
            st.pop();                   // Pop lower price from the stack
        }
        st.push({price, span});         // Push every pair of <price, span> to the stack
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */