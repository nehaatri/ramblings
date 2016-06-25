/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
 * Author: Neha Atri <neha.atri@gmail.com>
 *
 */

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    int count = 0;
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* temp = NULL;

    while (count < (m - 1)) {
      prev = curr;
      curr = curr->next;
      count++;
    }
    ListNode* temp1 = curr;
    ListNode* beforen = prev;
    prev = curr;
    curr = curr->next;
    count = 0;

    while (count < (n - m)) {
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
      count++;
    }
    temp1->next = curr;
    if (beforen)
      beforen->next = prev;
    else
      head = prev;
    return head;
  }
};
