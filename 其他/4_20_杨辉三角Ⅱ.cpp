//119. 杨辉三角 II
https://leetcode.cn/problems/pascals-triangle-ii/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};

        vector<int> ret(rowIndex + 1);
        ret[0] = 1;
		//复用数组构建，复用要从右向左遍历
        for (int i = 1; i <= rowIndex; ++i) {
            ret[i] = 1;
            for (int j = i - 1; j > 0; --j) {
                ret[j] = ret[j] + ret[j - 1];
            }
        }

        return ret;
    }
};