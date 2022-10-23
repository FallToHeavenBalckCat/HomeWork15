class MinStack {
public:
    /** initialize your data structure here. */
    /*因为所有的操作都要实现O(1)的时间复杂度，
    所以不能只维护一个栈，因为只有一个栈的话，
    可能面临栈顶指针需要来回遍历的情况，所以
    要维护两个栈，一个栈用来存储数据，另一个栈
    做成单调栈用来处理最小值；*/
    //data struct 
    stack<int> q;//普通栈存数据
    stack<int> min_q;//堆栈单调

    MinStack() {
        
    }
    
    void push(int x) {
        q.push(x);//普通栈直接插入即可；
        if(min_q.empty() || x<=min_q.top()) 
            min_q.push(x);
    }
    
    void pop() {
        if(q.top()==min_q.top())//如果数据栈和单调栈栈顶元素是一致的，
        //因为要普通栈的栈顶移除，所以也要将单调栈的栈顶移除
            min_q.pop();
        q.pop();
    }
    
    int top() {
        return q.top();
    }
    
    int getMin() {
        return min_q.top();
    }
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */