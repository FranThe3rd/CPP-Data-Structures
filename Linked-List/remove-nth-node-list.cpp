




/**
 * Given the head of a linked list and an integer n, remove the nth node from the end of the list and return its head.
 * Example 1:
 * Input: head = [1,2,3,4], n = 2
 * Output: [1,2,4]
 * Example 2:
 * Input: head = [5], n = 1
 * Output: []
 */


ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* dummy = new ListNode(0,head);
  ListNode* left = dummy;
  ListNode* right = head;
  while (n > 0) {
    right = right->next;
    n-=1;
  }
  while (right) {
    right = right->next;
    left = left->next;
  }
  left->next = left->next->next;
  return dummy->next;
}
