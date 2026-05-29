class MinStack {
private:
    // Node* head;
    stack<int> x;
    stack<int> y;

public:
    MinStack() {}
    
    void push(int val) {
        x.push(val);
        if (y.empty() || val<=y.top()){
            y.push(val);
        }
    }
    
    void pop() {
        int r = x.top();
        x.pop();
        if (!y.empty() && r==y.top() ) y.pop();
    }   
    
    int top() {
        return x.top();
    }
    
    int getMin() {
        return y.top();
    }
};
