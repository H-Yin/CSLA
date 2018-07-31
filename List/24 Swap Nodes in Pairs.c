/*
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/ 

#include<stdio.h>
#include<stdlib.h>
#include "MyList.h"
 //Definition for singly-linked list.

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = head ;
    pre->next = head;
    if(cur && cur->next){
        head = cur->next;
    }
    while(pre && cur && cur->next){
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = cur;
        pre = cur;
        cur = cur->next;
    }
    return head;
}

//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1,n=3;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for(i=0; i< n; i++){
//		pre_L1->val = i;
//		if (i!=n-1){
//			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        	pre_L1 = pre_L1->next;
//		}else{
//			pre_L1->next = NULL;
//		}
//	}
//	for(i=1; i< 10; i++){
//		pre_L2->val = i*i;
//		if (i!=9){
//			pre_L2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        	pre_L2 = pre_L2->next;
//		}else{
//			pre_L2->next = NULL;
//		}
//	}
//	// l1 = NULL;
//	printList(l1);
//    // printList(l2);
//	l3 = swapPairs(l1);
//	printList(l3);
//}



