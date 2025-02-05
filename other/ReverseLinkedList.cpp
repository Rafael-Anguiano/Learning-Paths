/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 *
 * Given the head of a linked list, reverse it and return the new head. 
 *
 * Space complexity: O(1)
 * Time complexity: O(n)
 *
 * a ->  b -> c -> d -> null
 *
 * prev -> null
 * curr -> a
 * next -> curr.next
 * curr.next = prev;
 * prev = curr;
 * curr = next;
 *
 * while(!curr)
 *
 */

ListNode* reverseLinkedList (ListNode* head) {
  ListNode* curr = head;
  ListNode* prev;
  ListNode* next;

  while (curr != nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}
