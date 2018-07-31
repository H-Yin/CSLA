/*

147. Insertion Sort List

Sort a linked list using insertion sort.
*/


#include<stdio.h>
#include<stdlib.h>
//Definition for singly-linked list.
#include "MyList.h"

/*
struct ListNode* insertionSortList(struct ListNode* head) {
	struct ListNode new_head;
	struct ListNode *cur = NULL, *pre = NULL;
	struct ListNode min, *min_pre = NULL;

	struct ListNode* watcher = &new_head;
	new_head.next = head;

	while (watcher && watcher->next)
	{
		pre = watcher;
		cur = watcher->next;
		min.val = (1 << 31) - 1;
		min.next = NULL;
		while (cur)
		{
			// <= not < for (1<<31)-1
			if (cur->val <= min.val){
				min_pre = pre;
				min.val = cur->val;
				min.next = cur;
			}
			cur = cur->next;
			pre = pre->next;
		}
		min_pre->next = min.next->next;
		min.next->next = watcher->next;
		watcher->next = min.next;
		watcher = watcher->next;
	}
	return new_head.next;
}*/
//
//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< 2; i++){
//		pre_L1->val = 2147483647-i;
//		if (i != 1){
//			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//			pre_L1 = pre_L1->next;
//		}
//		else{
//			pre_L1->next = NULL;
//		}
//	}
//
//	printList(l1);
//	l3 = insertionSortList(l1);
//	printList(l3);
//	getchar();
//}