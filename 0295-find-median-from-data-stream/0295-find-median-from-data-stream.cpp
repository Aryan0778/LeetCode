class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {  
    if(maxHeap.empty() || maxHeap.top()>num){
        maxHeap.push(num);
    }
    else{
        minHeap.push(num);
    }
    if(minHeap.size()>maxHeap.size()){
        int top=minHeap.top();
        minHeap.pop();
        maxHeap.push(top);
    }
    else if((maxHeap.size()-minHeap.size())>1){
        while(maxHeap.size()-minHeap.size()>1){
            int top=maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    }
    
    double findMedian() {
        if(minHeap.size()>0) cout<<minHeap.top()<<" ";
        else cout<<-1<<" ";
        cout<<maxHeap.top()<<endl;
        if(maxHeap.size()==minHeap.size()){
            return ((maxHeap.top()+minHeap.top())/2.0);
        }
        else{
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */