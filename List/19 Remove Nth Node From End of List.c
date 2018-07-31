/*
 
19 Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

*/ 

#include<stdio.h>
#include<stdlib.h>
#include "MyList.h"
//Definition for singly-linked list.

/* H.Yin
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *cur = head, *pre = head;
    int i = 1;
    // ������ n +1 �� , ��֤ cur��pre ��n+1�� 
    for (i; i <= n ; i++){
        cur = cur->next;
    }
    // ͬʱ�ƶ�cur, pre ֱ�� cur ����� 
    while(cur && cur->next){
        cur = cur->next;
        pre = pre->next;
    }
    // �ҵ�������n�� 
    // pre->val = pre->next->val;
    cur = pre->next;
    if (cur == NULL){
        if(!pre->next){
            free(head);
            head = NULL;
        }else{
            pre->val = pre->next->val;
            pre->next = pre->next->next;
        }
    }else{
        pre->next = pre->next->next;
    }

    free(cur);
    cur = NULL;
    
    return head;
}
*/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *cur = head;
    struct ListNode *pre = (struct ListNode*)malloc(sizeof(struct ListNode));
    pre->next = head;
    int i = 1;
    // ������ n +1 �� , ��֤ cur��pre ��n+1�� 
    for (i; i <= n ; i++){
        cur = cur->next;
    }
    if(!cur){
        
    }
    // ͬʱ�ƶ�cur, pre ֱ�� cur ����� 
    while(cur){
        cur = cur->next;
        pre = pre->next;
    }
    // �ҵ�������n�� 
        
    cur = pre->next;
    if(pre->next == head){
        head = pre->next->next;
    }
    pre->next = pre->next->next;
    free(cur);
    cur = NULL;
    
    return head;
}


//int main(){
//	struct ListNode *l1, *pre_L1, *l3;
//	int i = 1;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	for(i=9; i< 10; i++){
//		pre_L1->val = i;
//		if (i!=9){
//			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        	pre_L1 = pre_L1->next;
//		}else{
//			pre_L1->next = NULL;
//		}
//	}
//	printList(l1);
//    l3 = removeNthFromEnd(l1, 1);
//    printList(l3);
//}

