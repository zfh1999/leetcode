/*
设计一个数字容器系统，可以实现以下功能：

在系统中给定下标处 插入 或者 替换 一个数字。
返回 系统中给定数字的最小下标。
请你实现一个 NumberContainers 类：

NumberContainers() 初始化数字容器系统。
void change(int index, int number) 在下标 index 处填入 number 。如果该下标 index 处已经有数字了，那么用 number
替换该数字。 int find(int number) 返回给定数字 number 在系统中的最小下标。如果系统中没有 number ，那么返回 -1 。
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

// class NumberContainers {
// public:
//     NumberContainers() {
        
//     }
    
//     void change(int index, int number) {
//         if (index >= v_.size())
//             v_.resize(index + 1, 0);
//         v_[index] = number;
//     }

//     int find(int number)
//     {
//         auto it = std::find(v_.begin(), v_.end(), number);
//         if (it != v_.end())
//             return distance(v_.begin(), it);
//         else
//             return -1;
//     }

//   private:
//     vector<int> v_;
// };

// class NumberContainers {
// public:
//     NumberContainers() {
        
//     }

//     void change(int index, int number)
//     {
//         m_[index] = number;
//     }

//     int find(int number)
//     {
//         for (const auto &p : m_)
//         {
//             if (p.second == number)
//                 return p.first;
//         }
//         return -1;
//     }

//   private:
//     map<int, int> m_;
// };

// class NumberContainers {
// public:
//     NumberContainers() {
        
//     }

//     void change(int index, int number)
//     {
//         if (index_v_.contains(index))
//         {
//             v_indexs_[index_v_[index]].erase(index);
//             // if (v_indexs_[index_v_[index]].empty())
//             //     v_indexs_.erase(index_v_[index]);
//         }

//         index_v_[index] = number;

//         v_indexs_[number].insert(index);
//     }

//     int find(int number)
//     {
//         // if (v_indexs_.contains(number))
//         // {
//         //     return *v_indexs_[number].begin();
//         // }
//         // else
//         //     return -1;
//         if (v_indexs_[number].empty())
//             return -1;
//         return *v_indexs_[number].begin();
//     }

//   private:
//     unordered_map<int, int> index_v_;
//     unordered_map<int, set<int>> v_indexs_;
// };

class NumberContainers {
private:
    unordered_map<int, int> nums;
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> heaps;

public:
    NumberContainers() {

    }

    void change(int index, int number) {
        nums[index] = number;
        heaps[number].push(index);
    }

    int find(int number) {
        while (!heaps[number].empty() && nums[heaps[number].top()] != number) {
            heaps[number].pop();
        }
        if (heaps[number].empty()) {
            return -1;
        }
        return heaps[number].top();
    }
};


/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */