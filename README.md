### 250
* 前250道除去hard、数据库以及贪心的题目
* 所有动态规划的题目暂时使用递归(回溯)暴力求解

### 基础
* 88 归并排序
* 206 反转list
* 208 前缀树
* 94 树中序
* 102 树层次
* 144 树前序
* 145 树后续
* 146 Least Recently Used (LRU) cache
* 148 list的归并，需要空间复杂度为O(1)???
* slow/fast
```c++
ListNode* slow = head;
ListNode* fast = head->next;
while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
}
ListNode* mid = slow->next;
```

### 思路简单，实现简单
* 1
* 66
* 103
* 167
* 169
* 189
* 215 优先级队列
* 217
* 219
* 303
* 326
* 342
* 345
* 387
* 389 使用异或，不用map
  
### 思路复杂，实现简单
* 11 two point
* 26 two point
* 27 two point
* 39 回溯
* 40 回溯
* 162 二分
* 201 特定解法
* 258 数学问题，特定解法
* 263
* 268 特定解法
* 367 数学问题，特定解法
* 283 解法见27
* 338 特定解法，找规律
* 378 heap, std::priority_queue
* 383 计数排序的思想

### 思路简单，实现复杂
* 15 two point
* 16 two point
* 34 二分
* 48 矩阵原地操作
* 69 二分边界
* 71
* 91 DP使用BT实现，超时
* 374 二分查找的边界问题？？？
* 397 回溯，时间空间复杂度较高
* 414 特定解法，不能用优先级队列

### 思路复杂，实现复杂
* 31 特定解法
* 43 数学问题
* 130 BFS
* 133
* 179 string的比较
* 207 拓扑排序
* 209 滑动窗口
* 210 拓扑排序
* 227 真的难
* 264 
* 299 特定解法
* 300 std::lower_bound
* 400
* 448 特定解法



### 参考
* 花花酱LeetCode
* happygirlzt
