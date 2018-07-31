
/*
23 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#include<stdio.h>
#include<stdlib.h>
#include "MyList.h"
 //Definition for singly-linked list.

//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for(i=9; i< 10; i++){
//		pre_L1->val = i;
//		if (i!=9){
//			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        	pre_L1 = pre_L1->next;
//		}else{
//			pre_L1->next = NULL;
//		}
//	}
//	for(i=5; i< 6; i++){
//		pre_L2->val = i;
//		if (i!=5){
//			pre_L2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        	pre_L2 = pre_L2->next;
//		}else{
//			pre_L2->next = NULL;
//		}
//	}
//	printList(l1);
//	printList(l2);
//	l3 = addTwoNumbers(l1, l2);
//	printList(l3);
//}
