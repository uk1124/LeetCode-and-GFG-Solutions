class MyCircularQueue {
    vector<int> queue;
    int fr, qSize, k;
public:
    MyCircularQueue(int _k) : queue(vector<int>(_k)), fr(0), qSize(0), k(_k)  {    
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        queue[(fr + qSize) % k] = value;
        qSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        fr = (fr+1) % k;
        qSize--;
        return true;
    }
    
    int Front() {
        if(!isEmpty()) {
            return queue[fr];
        }
        return -1;
        
    }
    
    int Rear() {
        if(!isEmpty()) {
            return queue[(fr + qSize -1) % k];
        }
        return -1;
    }
    
    bool isEmpty() {
        return (qSize == 0);
    }
    
    bool isFull() {
        return (qSize == k);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */