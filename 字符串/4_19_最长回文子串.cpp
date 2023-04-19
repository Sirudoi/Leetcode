//5. 最长回文子串
//https://leetcode.cn/problems/longest-palindromic-substring/
//manacher算法
class Solution {
private:
    int begin = 0;
    int maxLen = 0;
public:
    string manacherStr(string& s) {
        string ret = "#";
        for (auto& c : s) {
            ret += c;
            ret += "#";
        }

        return ret;
    }
    string longestPalindrome(string s) {
        if (s.size() == 0) return 0;

        string str = manacherStr(s);
        //回文半径数组
        vector<int> arr(str.size(), 0);
        //最右回文边界
        int R = -1;
        //取最右时，下标i
        int C = -1;

        for (int i = 0; i < str.size(); ++i) {
            //i < R：取i'的半径和R - i中小的那个
            //i'半径在[L, R]内，取i'的半径
            //i'半径在[L, R]外，取R - i
            //i > R：取1
            arr[i] = i < R ? min(arr[2 * C - i], R - i) : 1;
            
            //中心扩展
            //左边界i - arr[i], 右边界i + arr[i]
            while (i - arr[i] >= 0 && i + arr[i] < str.size() && str[i - arr[i]] == str[i + arr[i]]) {
                arr[i]++;
            }

            //更新R和C
            if (arr[i] > R) {
                R = arr[i];
                C = i;
            }
			//记录对应的位置
            if (arr[i] > maxLen) {
				//最长半径表示抵达下标 + 1，这里要减回去
                maxLen = arr[i] - 1;
                begin = (i - maxLen) / 2;
            }
        }
        // cout << begin << maxLen << endl;
        return s.substr(begin, maxLen);
    }
};