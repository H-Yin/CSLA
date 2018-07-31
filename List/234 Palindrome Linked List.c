/*
234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.
*/


#include<stdio.h>
#include<stdlib.h>

#include <stdbool.h>

#include "MyList.h"

/* 迭代法
struct ListNode* reverseList(struct ListNode* head) {
struct ListNode new_head;
struct ListNode *pre = head, *cur = NULL, *new_pre = NULL;
new_head.next = head;
new_pre = &new_head;
while (pre && pre->next)
{
cur = pre->next;
// 头插法
pre->next = cur->next;
cur->next = new_pre->next;
new_pre->next = cur;
}
return new_head.next;
}

*/

bool isPalindromeList(struct ListNode* head) {
	struct ListNode new_head;
	struct ListNode *pre = head, *cur = head, *new_pre = head;
	int i, n = 0;
	if (!head || !head->next)
	{
		return true;
	}
	while (cur)
	{
		cur = cur->next;
		n++;
	}

	for (cur = head, i = 0; i < (n-1) / 2; i++){
		new_pre = new_pre->next;
	}
	printf("%d\n", new_pre->val);
	pre = new_pre->next;
	new_pre->next = NULL;
	new_head.next = pre;
	printList(head);
	while (pre && pre->next)
	{
		cur = pre->next;
		// 头插法
		pre->next = cur->next;
		cur->next = new_head.next;
		new_head.next = cur;
	}
	cur = head;
	pre = new_head.next;
	printList(new_head.next);
	while (cur && pre && cur->val == pre->val)
	{
		cur = cur->next;
		pre = pre->next;
	}
	if (cur==NULL || pre == NULL)
	{
		return true;
	}
	return false;
}


//
//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3, *look = NULL;
//	int i = 1, n=10;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	n = 9;
//	for (i = 0; i< n; i++){
//		pre_L1->val = i+1>5? 9-i : i+1;
//		if (i != n - 1){
//			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//			pre_L1 = pre_L1->next;
//		}
//		else{
//			pre_L1->next = NULL;
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
//	printList(l1);
//	// printList(l2);
//	// l3 = isPalindrome(l1);
//	if (isPalindrome(l1)){
//		printf("true");
//	}
//	else{
//		printf("false");
//	}
//
//	// printList(l3);
//	getchar();
//}
