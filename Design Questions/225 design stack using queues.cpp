class MyStack {
public:
    deque<int>stack;
    MyStack() {
        
    }
    
    void push(int x) {
        stack.push_front(x);
    }
    
    int pop() {
        int pop = stack.front();
         stack.pop_front();
         return pop;
    }
    
    int top() {
        return stack.front();
    }
    
    bool empty() {
        if(stack.size()>0)return false;
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//TC:O(1)
//SC:O(1)