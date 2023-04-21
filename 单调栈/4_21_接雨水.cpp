//42. 接雨水
//https://leetcode.cn/problems/trapping-rain-water/
class Solution {
private:
    stack<int> _st;
    int _ans = 0;

public:
    int trap(vector<int>& height) {
        for (int i = 0; i < height.size(); ++i) {
            while (!_st.empty() && height[_st.top()] < height[i]) {
                //栈顶出栈
                int topIndex = _st.top();
                _st.pop();
                //栈还有元素，计算雨水
                if (_st.size() >= 1) {
                    //[左边比他大下标, 栈顶元素下标, 右边比他大下标]
                    //宽度 = 右边比他大下标 - 左边比他大小标 - 1
                    //高度 = min(左边比他大值, 右边比他大值) - 栈顶元素值
                    int width = i - _st.top() - 1;
                    int high = min(height[_st.top()], height[i]) - height[topIndex];
                    _ans += width * high;
                }
            }
            
            //栈为空 || 栈元素只有一个 || 计算完后
            //压栈
            _st.push(i);
        }

        return _ans;
    }
};