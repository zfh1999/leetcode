/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 */

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        lists.erase(remove_if(lists.begin(), lists.end(), [](auto p) { return !p; }), lists.end());
        std::priority_queue q{[](auto &a, auto &b) { return a->val > b->val; }, lists};
        ListNode head;
        for (auto p = &head; !q.empty(); q.pop()) {
            p = p->next = q.top();
            if (p->next) q.push(p->next);
        }
        return head.next;
    }
};

int main() {
    Solution so;

}