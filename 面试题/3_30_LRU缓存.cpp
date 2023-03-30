//leetcode146 LRU缓存 中等
//https://leetcode.cn/problems/lru-cache/
struct DLinkNode
{
    DLinkNode* _prev;
    DLinkNode* _next;
    int _key;
    int _value;

    DLinkNode() : _key(0), _value(0), _prev(nullptr), _next(nullptr) {}
    DLinkNode(int key, int value) : _key(key), _value(value), _prev(nullptr), _next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : _size(0), _capacity(capacity), _head(nullptr)
    {
        _head = new DLinkNode();
    }

    int get(int key)
    {
        auto it = _map.find(key);
        if (it == _map.end())
        {
            return -1;
        }
        MoveToHead(key);

        return it->second->_value;
    }

    void put(int key, int value)
    {
        auto iter = _map.find(key);
        if (iter != _map.end())
        {
            iter->second->_value = value;
            MoveToHead(key);
            return;
        }

        if (iter == _map.end() && _size >= _capacity)
        {
            RemoveNode();
        }
        AddNode(key, value);
    }

    void RemoveNode()
    {
        DLinkNode* target = _head->_prev;
        if (!target) return;
        DLinkNode* prev = target->_prev;

        // 删除节点
        _head->_prev = prev; //重置链表尾元素
        prev->_next = _head;

        // 删除映射
        auto it = _map.find(target->_key);
        _map.erase(it);
        --_size;

        // 回收
        delete target;
        target = nullptr;
    }

    void AddNode(const int& key, const int& value)
    {
        DLinkNode* node = new DLinkNode(key, value);

        // 头插，第一个节点
        if (!_head->_next)
        {
            _head->_next = node;
            _head->_prev = node;

            node->_prev = _head;
            node->_next = _head;
        }
        // 非第一个节点
        else
        {
            DLinkNode* next_node = _head->_next;

            node->_next = next_node;
            node->_prev = _head;

            next_node->_prev = node;
            _head->_next = node;
        }

        // 构建映射
        _map[key] = node;
        ++_size;
    }

    void MoveToHead(const int& key)
    {
        auto it = _map.find(key);

        DLinkNode* cur = it->second;
        DLinkNode* prev = cur->_prev;
        DLinkNode* next = cur->_next;

        // 调整双链表
        prev->_next = next;
        if (next) next->_prev = prev;

        // 把目标节点调整到链表头
        cur->_next = _head->_next;
        cur->_prev = _head;
        _head->_next = cur;
        cur->_next->_prev = cur;
    }

private:
    int _size;
    int _capacity;
    DLinkNode* _head;
    unordered_map<int, DLinkNode*> _map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */