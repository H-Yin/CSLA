

#include<stdio.h>
#include<stdlib.h>
//Definition for singly-linked list.
struct RandomListNode {
	int label;
	struct RandomListNode *next;
	struct RandomListNode *random;
};

//struct RandomListNode *copyRandomList(struct RandomListNode *head) {
//	struct RandomListNode new_head;
//	struct RandomListNode *pre = head, *new_pre = &new_head, *new_cur = NULL;
//	new_head.next = NULL;
//	while(pre)
//	{
//		new_cur = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
//		new_cur->label = pre->label;
//		new_cur->next = NULL;
//		new_cur->random = NULL;
//
//		new_pre->next = new_cur;
//		new_pre = new_pre->next;
//		pre = pre->next;
//	}
//	pre = head
//	while()
//}
//
//int main(){
//	struct RandomListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1;
//	l1 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
//	l2 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< 10; i++){
//		pre_L1->label = i % 2 ? i : 10 - i;
//		if (i != 9){
//			pre_L1->next = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
//			pre_L1 = pre_L1->next;
//		}
//		else{
//			pre_L1->next = NULL;
//		}
//	}
//
//	printList(l1);
//	// printList(l2);
//	l3 = reverseBetween(l1);
//	printList(l3);
//	getchar();
//}