//347. 前 K 个高频元素
//https://leetcode.cn/problems/top-k-frequent-elements/submissions/
//第一次我写的，我建了大堆，这边等于是堆排序了
//建大堆需要把全部元素放入堆里面，不想小堆只需要维护最小的
//并且大堆删元素比较麻烦
class Solution {
private:
    unordered_map<int, int> _hashMap;
    vector<int> _ans;
public:
    struct Greater {
        bool operator()(const pair<int, int>& e1, const pair<int, int>& e2) {
            return e1.second < e2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (const auto& it : nums) {
            _hashMap[it]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Greater> q;
        for (const auto& it : _hashMap) {
            q.push(make_pair(it.first, it.second));
        }

        for (int i = 0; i < k; ++i) {
            auto top = q.top();
            q.pop();
            _ans.emplace_back(top.first);
        }

        return _ans;
    }
};

class Solution {
private:
    unordered_map<int, int> _hashMap;
    vector<int> _ans;
public:
    //前k大，建小堆
    struct Compare {
        bool operator()(const pair<int, int>& e1, const pair<int, int>& e2) {
            return e1.second > e2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //计数
        for (const auto& it : nums) {
            _hashMap[it]++;
        }

        Compare cmp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
        //建堆
        for (const auto& it : _hashMap) {
            //堆大小为k，比较堆顶和当前，大的入堆
            if (q.size() == k) {
                if (q.top().second < it.second) {
                    q.pop();
                    q.push(it);
                }
            }
            else {
                q.push(it);
            }
        }

        //当前大小为k的堆里面所有数据即为所求
        for (int i = 0; i < k; ++i) {
            auto top = q.top();
            q.pop();
            _ans.emplace_back(top.first);
        }

        return _ans;
    }
};