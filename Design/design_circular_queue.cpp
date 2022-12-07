class MyCircularQueue {
 private:
        vector<int> v;
        int front=-1,back=-1;
            
public: 
    MyCircularQueue(int k):v(k) {}
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(front==-1){
            front++;
        }
        back=(back+1)%v.size();
        
        v[back]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front==back){
            front=-1;
            back=-1;
        }
        else front=(front+1)%v.size();
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return v[back];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return !isEmpty() and (back+1)%v.size()==front;
    }
};
