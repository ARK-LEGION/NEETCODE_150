class MedianFinder {
private:
    priority_queue<int> low;
    priority_queue<int, vector<int>,greater<int>> high;
    int size;
public:
    MedianFinder() {    
        size=0;
    }
    
    void addNum(int num) {
        size++;
        if (low.empty()) {
            low.push(num);
            return;
        }
        if (num<=low.top()){
            if (low.size()<(size+1)/2) low.push(num);
            else {
                int x = low.top();
                low.pop();
                low.push(num);
                high.push(x);
            }
        }       
        else{
            if (high.empty()){
                high.push(num);
                return;
            }
            if (num>high.top()){
                int x = high.top();
                if (low.size() < (1+size)/2){
                    high.pop();
                    high.push(num);
                    low.push(x);
                }
                else{
                    high.push(num);
                }
            }
            else{
                if (low.size()<(1+size)/2)low.push(num);
                else{
                    high.push(num);
                }
            }

        }
    }
    
    double findMedian() {
        if (low.size()!=high.size()) return low.top();
        return (low.top()+high.top())/(double)2;
    }
};
