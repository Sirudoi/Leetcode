//155. 最小栈
//https://leetcode.cn/problems/min-stack/
//两个栈模拟，第二个栈专门存储当前元素在栈内的最小值
class MinStack {
private:
    stack<int> _st;
    stack<int> _m_st;

public:
    MinStack() {}
    
    void push(int val) {
        if (_st.empty()) {
            _m_st.push(val);
        } else {
            _m_st.push(min(_m_st.top(), val));
        }
        _st.push(val);
    }
    
    void pop() {
        _st.pop();
        _m_st.pop();
    }
    
    int top() {
        return _st.top();
    }
    
    int getMin() {
        return _m_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */