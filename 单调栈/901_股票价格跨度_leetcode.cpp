class StockSpanner {
public:
    StockSpanner() {
        st_.emplace(make_pair(-1, INT_MAX));
        index_ = -1;
    }
    
    int next(int price) {
        // 本质是找出左边第一个比当前值大的元素的位置
        // 采用单调栈, 找大, 因此使用单调递增栈
        ++index_;

        // 栈顶元素比当前元素小, 出栈更新信息
        while (price >= st_.top().second) {
            st_.pop();
        }

        int ret = index_ - st_.top().first;
        st_.emplace(make_pair(index_, price));
        return ret;
    }
private:
    stack<std::pair<int, int>> st_; // 单调栈
    int index_;                     // 当前插入索引
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */