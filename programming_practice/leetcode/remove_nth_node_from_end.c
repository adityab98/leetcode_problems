/*
 * Given the head of a linked list, remove the nth node from the end of the list
 * and return its head.
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode *head, int n){
	struct ListNode **head_ptr = &head;
	struct ListNode *tmp = head;
	int i = 0;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		i++;
	}
	if (!i)
		return NULL;
	else if (i-n+1 == 0)
		return head->next;
	struct ListNode **tail_ptr = &tmp;
	printf("%d\n", tmp->val); 
	int j = 0;
	tmp = *head_ptr;
	while (j++ < (i - n))
		tmp = tmp->next;
	printf("%d\n", tmp->val); 
	tmp->next = tmp->next->next;
	return *head_ptr;
}
