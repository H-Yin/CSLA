

#include<stdio.h>

#include<stdlib.h>

#include <stdbool.h>

#include "MyList.h"

bool hasCycle(struct ListNode *head) {
	struct ListNode *fast = head, *slow = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow){
			return  1;
		}
	}
	return 0;
}

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *fast = head, *slow = head, *entry = NULL;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow){
			entry = slow;
			break;
		}
		printf("F:%d  S:%d\n", fast->val, slow->val);
	}
	if (entry == NULL){
		return NULL;
	}
	fast = head;
	while (fast != entry)
	{
		printf("F:%d  E:%d\n", fast->val, entry->val);
		fast = fast->next;
		entry = entry->next;
	}
	return entry;
}
//
//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3 , *look = NULL;
//	int i = 1;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< 10; i++){
//		pre_L1->val = i;
//		if (i == 1){
//			look = pre_L1;
//		}
//		if (i != 9){
//			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//			pre_L1 = pre_L1->next;
//		}
//		else{
//			pre_L1->next = look;
//		}
//	}
//	/*
//	for(i=5; i< 6; i++){
//	pre_L2->val = i;
//	if (i!=5){
//	pre_L2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L2 = pre_L2->next;
//	}else{
//	pre_L2->next = NULL;
//	}
//	}*/
//	// printList(l1);
//	// printList(l2);
//	l3 = detectCycle(l1);
//	// printList(l3);
//	printf("---%d\n", l3->val);
//	getchar();
//}
