class LRUCache {
public:
  LRUCache(int capacity):capacity_(capacity){

  }

  int get(int key) {
    if (m_.find(key) != m_.end()) {
      int value = m_[key]->second;
      l_.erase(m_[key]);
      l_.push_front(make_pair(key, value));
      m_[key] = l_.begin();
      return m_[key]->second;
    }
    return -1;
  }

  void put(int key, int value) {
    if (m_.find(key) == m_.end()) { // 没找到
      l_.push_front(make_pair(key, value));
      m_.emplace(key, l_.begin());
      if (l_.size() == capacity_+1) {
        auto last = --l_.end();
        m_.erase(last->first);
        l_.erase(last);
      }
    } else { // 找到
      l_.erase(m_[key]);
      l_.push_front(make_pair(key, value));
      m_[key] = l_.begin();
    }
  }
private:
  list<pair<int ,int>> l_;
  unordered_map<int, list<pair<int, int>>::iterator> m_;
  uint32_t capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */