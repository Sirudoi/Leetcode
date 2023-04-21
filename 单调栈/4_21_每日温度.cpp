//739. 每日温度
//https://leetcode.cn/problems/daily-temperatures/
//单调栈
class Solution {
private:

public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size());

        for (int i = 0; i < temperatures.size(); ++i) {
            //栈空，直接入栈
            if (st.empty()) {
                st.push(i);
            }
            //栈不为空
            else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    //出栈，生成栈顶信息
                    int top = st.top();
                    st.pop();
                    ans[top] = i - top;
                }
                st.push(i);
            }
        }

        return ans;
    }
};