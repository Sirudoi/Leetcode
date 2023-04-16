//283. 移动零
//https://leetcode.cn/problems/move-zeroes/
//O（1）原地，冒泡，但是这个冒泡时间超过了5%，太抽象了
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size() - i - 1; ++j) {
                if (nums[j] == 0) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};

//双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;

        //左边界表示处理好的数组的下一个位置
        //右指针找非零数，往左边界位置放，遇到零直接跳过
        //然后更新左边界

        while (right < nums.size()) {
            //找非零数，往左边界位置放
            if (nums[right]) {
                swap(nums[left], nums[right]);
                //放完更新左边界
                ++left;
            }
            ++right;
        }
    }
};