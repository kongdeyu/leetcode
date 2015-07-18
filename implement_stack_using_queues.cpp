class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        _queue_main.push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        if(empty())
        {
            return;
        }
        
        while(_queue_main.size() > 1)
        {
            _queue_slave.push(_queue_main.front());
            _queue_main.pop();
        }
        _queue_main.pop();
        _queue_main.swap(_queue_slave);
    }
    
    // Get the top element.
    int top() {
        int element = 0;
        while(_queue_main.size())
        {
            element = _queue_main.front();
            _queue_slave.push(element);
            _queue_main.pop();
        }
        _queue_main.swap(_queue_slave);
        return element;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return _queue_main.empty();
    }
    
private:
    std::queue<int> _queue_main;
    std::queue<int> _queue_slave;
};