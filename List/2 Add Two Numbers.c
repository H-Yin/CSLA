/*
 
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/ 

#include<stdio.h>
#include<stdlib.h>
#include "MyList.h"

 //Definition for singly-linked list.

/*  H.Yin
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* pre = NULL, *cur = NULL;
	struct ListNode* pre_L1 = l1, *pre_L2 = l2;
	struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur = res;
    int carry = 0;
    while(pre_L1 && pre_L2 && cur) {
    	
        cur->val = (pre_L1->val + pre_L2->val + carry) % 10;
        carry = (pre_L1->val + pre_L2->val + carry) / 10;
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pre = cur;
        cur = cur->next;
        
        pre_L1 = pre_L1->next;
        pre_L2 = pre_L2->next;
    }
    
    // if L1's length > L2's length => pre_L1 is Not empty, while pre_L2 is empty 
    while(pre_L1 && cur){
    	cur->val = (pre_L1->val + carry) % 10;
        carry = (pre_L1->val + carry) / 10;
        
        pre_L1 = pre_L1->next;
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pre = cur;
		cur = cur->next;
	}
	// if L1's length < L2's length => pre_L1 is Not empty, while pre_L2 is empty 
	while(pre_L2 && cur){
		cur->val = (pre_L2->val + carry) % 10;
        carry = (pre_L2->val + carry) / 10;
        
        pre_L2 = pre_L2->next;
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pre = cur;
        cur = cur->next;
	}
	printf("%d\n", carry);
	// save carry as the highest bit 
	if (carry){
		cur->val = carry;
		cur->next = NULL;
	}else{
		free(pre->next);
		pre->next = NULL;
	}
	return res;
}

*/

/* 优化版：参照solution 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *pre_L1 = l1, *pre_L2 = l2 , *pre = NULL, *cur = NULL;
	struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur = res;
    int carry = 0,x,y;
    while(pre_L1 || pre_L2) {
    	x = pre_L1 ? pre_L1->val : 0;
    	y = pre_L2 ? pre_L2->val : 0;
    	
        cur->val = (x + y + carry) % 10;
        carry = (x + y + carry) / 10;
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pre = cur;
        cur = cur->next;
        
        pre_L1 = pre_L1 ? pre_L1->next : NULL;
        pre_L2 = pre_L2 ? pre_L2->next : NULL;
    }
	printf("%d\n", carry);
	// save carry as the highest bit 
	if (carry){
		cur->val = carry;
		cur->next = NULL;
	}else{
		free(pre->next);
		pre->next = NULL;
	}
	return res;
}
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *pre_L1 = l1, *pre_L2 = l2 , *pre = NULL, *cur = NULL;
	struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur = res;
    int carry = 0,x,y,sum;
    while(pre_L1 || pre_L2) {
        cur->next  = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        // 结束的链表元素值，视为 0 
    	x = pre_L1 ? pre_L1->val : 0;
    	y = pre_L2 ? pre_L2->val : 0;
    	sum = x + y + carry;
        if(sum >= 10){
            cur->val = sum - 10;
            carry = 1;
        }else{
            cur->val = sum;
            carry = 0;
        }
        cur->next = NULL;
        // 只循环没有结束的链表 
        if(pre_L1){
            pre_L1 = pre_L1->next;
        }
        if(pre_L2){
            pre_L2 = pre_L2->next;
        }
    }
	// 保存进位 
	if (carry){
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
		cur->val = carry;
		cur->next = NULL;
	}
	return res->next;
}


//
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
//
