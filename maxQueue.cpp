#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


class MaxQueue {
    queue<int> que;
    deque<int> deq;
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        return deq.empty() ? -1 : deq.front;
    }
    
    void push_back(int value) {
        que.push(value);
        //当value值比队列中的某些值大时， 将双向列表中所有
        //小于x的元素弹出
        while(!deq.empty() && deq.back() < value)
            deq.pop_back();
        deq.push_back(value);
    }
    
    
    int pop_front() {
        if(que.empty()) return -1;
        int val = que.front();
        //若出队元素时最大元素，双向队列需要同时将首元素出队
        
        if(val == deq.front())
            deq.pop_front();
        que.pop();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */