//239. 滑动窗口最大值
//https://leetcode.cn/problems/sliding-window-maximum/
//双端单调栈
class Solution {
private:
    deque<int> _dq;
    vector<int> _ans;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//先入k个元素，保证栈内单调递减
        for (int i = 0; i < k; ++i) {
            while (!_dq.empty() && nums[_dq.back()] <= nums[i]) {
                _dq.pop_back();
            }
            _dq.push_back(i);
        }
        _ans.push_back(nums[_dq.front()]);

		//如果当前元素 >= 队尾元素，那么队尾元素永远不可能是最大的
		//因为当前元素 == 队尾元素，队尾先过期
		//因为当前元素 > 队尾元素，队尾不但先过期，而且小于当前元素
        for (int i = k; i < nums.size(); ++i) {
            while (!_dq.empty() && nums[_dq.back()] <= nums[i]) {
                _dq.pop_back();
            }
            _dq.push_back(i);

            //队头元素在滑动窗口最左侧，弹出
            //front [ .... i] 
            //front = i - k;
            if (_dq.front() <= i - k)
                _dq.pop_front();
            
            _ans.push_back(nums[_dq.front()]);

        }

        return _ans;
    }
};