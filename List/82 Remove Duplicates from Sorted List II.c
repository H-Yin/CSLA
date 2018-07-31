/*

82. Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

#include<stdio.h>
#include<stdlib.h>
#include "MyList.h"
//Definition for singly-linked list.

struct ListNode* deleteDuplicates2(struct ListNode* head) {
	struct ListNode *new_head = NULL, *pre = head, *cur = head;
	struct ListNode *new_cur = NULL;
	new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	 new_head->next = head;
	 new_cur = new_head;

	int val = 0, flag = 0;
	while (pre && pre->next){
		cur = pre->next;
		// 删除相同的（除了子链的头节点）
		if (pre->val == cur->val)
		{
			pre->next = cur->next;
			free(cur);
			cur = pre->next;			
			flag = 1;
			continue;
		}
		// 删除子链的头结点
		if(flag == 1)
		{
			new_cur->next = pre->next;
			free(pre);
			pre = new_cur->next;
			flag = 0;
		}
		else
		{
			// 不存在 相同序列
			new_cur = new_cur->next;
			pre = new_cur->next;
		}
	}
	// 整个序列的值都相同，则最后会剩1个头结点
	if (flag == 1 && pre)
	{
		new_cur->next = pre->next;
		free(pre);
		pre = NULL;
	}
	return new_head->next;
}


//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< 10; i++){
//		// pre_L1->val = i<7  ? i>3 ? 1: 4: i;
//		pre_L1->val = 1;
//		if (i != 9){
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
//	l3 = deleteDuplicates2(l1);
//	printList(l3);
//	getchar();
//}
