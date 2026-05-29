// class Node{
//     int v;
//     Node* next;
// public:
//     Node(int v, Node* next){
//         this->v= v;
//         this->next = next;
//     }
//     Node(int v){
//         this->v= v;
//     }
//     Node(){}
// };

class MinStack {
private:
    // Node* head;
    stack<int> x;
    stack<int> y;

public:
    MinStack() {
          
    }
    
    void push(int val) {
        x.push(val);
        if (y.empty() || val<y.top()){
            y.push(val);
        }
        else {
            int cnt=0;
            while (!y.empty() && y.top()<val){
                cnt++;
                x.push(y.top());
                y.pop();
            }
            y.push(val);
            while (cnt--){
                y.push(x.top());
                x.pop();
            }
        }
    }
    
    void pop() {
        int r = x.top();
        x.pop();
        int cnt=0;
        while (!y.empty() && y.top()!=r){
            cnt++;
            x.push(y.top());
            y.pop();
        }
        y.pop();
        while (cnt--){
            y.push(x.top());
            x.pop();
        }
    }   
    
    int top() {
        return x.top();
    }
    
    int getMin() {
        return y.top();
    }
};
