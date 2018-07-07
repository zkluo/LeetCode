/*
 * 基础链表题
 * Author: Luo Zhikun
 * Date: 2018/7/7
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        int len = 0;
        ListNode* last = NULL;
        ListNode* first = NULL;
        first = head;
        while (head != NULL) {
            if (head->next == NULL) {
                last = head;
            }
            head = head->next;
            len++;
        }
        if (k % len == 0)
            return first;
        int step = len - (k % len) - 1;
        int index = 0;
        head = first;
        while (index < step) {
            head = head->next;
            index++;
        }
        ListNode* result = head->next;
        head->next = NULL;
        last->next = first;
        return result;
    }
};
