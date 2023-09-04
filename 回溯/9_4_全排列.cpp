// https://leetcode.cn/problems/permutations/submissions/
// 46. 全排列

class Solution {
public:
    vector<vector<int>> ans_;   
    vector<int> path_;
    vector<bool> visited_; // 存储某个元素是否使用过

public:
    void backtrack(vector<int>& nums) {
        if (path_.size() == nums.size()) {
           ans_.emplace_back(path_);
           return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (true == visited_[i])
                continue;
            path_.emplace_back(nums[i]);
            visited_[i] = true;

            backtrack(nums);

            path_.pop_back();
            visited_[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        visited_.resize(n, false);

        backtrack(nums);

        return ans_;
    }
};