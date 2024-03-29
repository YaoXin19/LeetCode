### 250
* 前250道除去hard、数据库以及贪心的题目
* 部分250以后的题目
* 所有动态规划的题目暂时使用递归(回溯)暴力求解

### 基础
* 7. Reverse Integer
* 88 归并排序
* 206 反转list
* 208 前缀树
* 94 树中序
* 102 树层次
* 105 由先序中序构建二叉树
* 106 由后序中序构建二叉树
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

### level 1 思路简单，实现简单
* 1
* 9
* 19
* 20
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
  
### level 2 思路复杂，实现简单
* 3 two point
* 11 two point
* 26 two point
* 27 two point
* 38 std::vector<std::pair<char, int>>
* 39 回溯
* 40 回溯
* 150 std::function与lamda
* 162 二分
* 200 BFS
* 201 特定解法
* 204 求质数
* 220 std::map::lower_bound
* 221 DP
* 258 数学问题，特定解法
* 263
* 268 特定解法
* 367 数学问题，特定解法
* 283 解法见27
* 338 特定解法，找规律
* 378 heap, std::priority_queue
* 383 计数排序的思想

### level 3 思路简单，实现复杂
* 2 
* 15 注意去重
* 16 two point
* 29 边界条件INT_MIN，INT_MAX
* 34 二分
* 48 矩阵原地操作
* 69 二分边界
* 71
* 91 DP使用BT实现，超时
* 143 list基本操作:求中点、反转、合并
* 241 分治
* 374 二分查找的边界问题？？？
* 397 回溯，时间空间复杂度较高
* 414 特定解法，不能用优先级队列

### level 4 思路复杂，实现复杂
* 5 求最长回文子串, 最优解-马拉车
* 8 其实不是很复杂
* 31 特定解法
* 43 数学问题
* 127 BFS
* 130 BFS
* 133
* 166 ???
* 179 string的比较
* 207 拓扑排序
* 209 滑动窗口
* 210 拓扑排序
* 227 真的难
* 229 摩尔投票
* 264 
* 299 特定解法
* 300 std::lower_bound
* 400
* 448 特定解法

### Two Pointer
#### 两边向中间
#### 快慢指针
##### 快指针增加元素，慢指针减小元素,记录vector的最小(大)长度
- 3 


### 编号顺序
- 1
- 2 

### BT改DP
- 5	Longest Palindromic Substring


### 参考
* 花花酱LeetCode
* happygirlzt
