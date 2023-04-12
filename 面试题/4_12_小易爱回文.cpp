//3.小易爱回文
//小易得到了一个仅包含大小写英文字符的字符串，该字符串可能不是回文串。（“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串，“asds”就不是回文串。）

//小易可以在字符串尾部加入任意数量的任意字符，使其字符串变成回文串。

//现在请你编写一个程序，程序要能计算出小易可以得到的最短回文串。

//这题就是给你个字符串，要生成回文数
//abnoo -> [4,5]是回文，后续逆置补充[1, 3]
//helloworld -> 没有回文，以最后一个数为中心，逆置补充前面的
//所以这题就是找到[i, s.size() - 1]中i最大的回文数
//然后在末尾补充[0, i - 1]的逆置字符串
#include <endian.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
bool isRevolve(string& s, int left, int right) {
    if (left > right)
        return false;
 
    while (left <= right) {
        if (s[left] != s[right])
            return false;
        ++left;
        --right;
    }
    return true;
}
 
string createStr(string& s, int index) {
    // cout << "index:" << index << endl;
    string end = s.substr(0, index);
    reverse(end.begin(), end.end());
    return s + end;
}
 
int main() {
    string s;
    cin >> s;
 
    int mid = s.size();
    for (int i = 0; i < s.size(); ++i) {
        //[i, end]回文，end后面补全[0, i - 1]
        if (isRevolve(s, i, s.size() - 1)) {
            mid = i;
            break;
        }
    }
    cout << createStr(s, mid) << endl;
}
// 64 位输出请用 printf("%lld")