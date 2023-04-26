//560. 和为 K 的子数组
//https://leetcode.cn/problems/subarray-sum-equals-k/
//前缀和
//假设nums数组前i项和为sum[i]
//要使得区间[i, j]取得一段数组的和为k, 则有: sum[i] - sum[j - 1] = k
//sum[j - 1] = sum[i] - k
//以i结尾，和为k的子数组的个数 -> [0, i]中，前缀和为:sum[i] - k的个数有多少个
//用哈希表记录个数
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};