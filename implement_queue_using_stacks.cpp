class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        _stack_main.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if(empty())
        {
            return;
        }
        
        if(_stack_slave.size())
        {
            _stack_slave.pop();
        }
        else
        {
            while(_stack_main.size() > 1)
            {
                _stack_slave.push(_stack_main.top());
                _stack_main.pop();
            }
            _stack_main.pop();
        }
    }
    
    // Get the front element.
    int peek(void) {
        if(empty())
        {
            return 0;
        }
        
        if(_stack_slave.size())
        {
            return _stack_slave.top();
        }
        
        int res = 0;
        while(_stack_main.size())
        {
            res = _stack_main.top();
            _stack_main.pop();
            _stack_slave.push(res);
        }
        return res;
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return _stack_main.empty() && _stack_slave.empty();
    }
    
private:
    std::stack<int> _stack_main;
    std::stack<int> _stack_slave;
};