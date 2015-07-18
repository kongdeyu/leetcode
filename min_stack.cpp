class MinStack {
public:
    void push(int x) {
        if(_min.empty() || _min.top() > x)
        {
            _min.push(x);
        }
        else
        {
            _min.push(_min.top());
        }
        _element.push(x);
    }
    
    void pop() {
        _element.pop();
        _min.pop();
    }
    
    int top() {
        return _element.top();
    }
    
    int getMin() {
        return _min.top();
    }
    
private:
    std::stack<int> _element;
    std::stack<int> _min;
};