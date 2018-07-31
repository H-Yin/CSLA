/*
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/ 

#include<stdio.h>
#include<stdlib.h>
#include "MyList.h"

/* Version 1
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *pre_L1 = l1, *pre_L2 = l2, *cur;
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res->next  = NULL;
    cur = res; 
    while(pre_L1 || pre_L2){
        while( pre_L1 && pre_L2 && pre_L1->val <= pre_L2->val){
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = cur->next;
            cur->val = pre_L1->val;
            cur->next = NULL;
            // printf("1-asa:%d\n",cur->val);
            pre_L1 = pre_L1->next;
        }
        while( pre_L2 && pre_L1 && pre_L2->val < pre_L1->val){
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = cur->next;
            cur->val = pre_L2->val;
            cur->next = NULL;
            // printf("2-asa:%d\n",cur->val);
            pre_L2 = pre_L2->next;
        }
        while(pre_L1 && !pre_L2){
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = cur->next;
            cur->val = pre_L1->val;
            cur->next = NULL;
            // printf("3-asa:%d\n",cur->val);
            pre_L1 = pre_L1->next;
        }
        while(!pre_L1 && pre_L2){
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = cur->next;
            cur->val = pre_L2->val;
            cur->next = NULL;
            // printf("4-asa:%d\n",cur->val);
            pre_L2 = pre_L2->next;
        }
    }
    return res->next;   
}

*/
// Verson 2
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *pre_L1 = l1, *pre_L2 = l2, *cur;
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res->next  = NULL;
    cur = res; 
    while(pre_L1 || pre_L2){
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        if (pre_L1){ // L1 不比L2短 
            if (pre_L2){ // L2 还没遍历完 
                if(pre_L1->val <= pre_L2->val){ // l1 值 比 l2 值小 
                    cur->val = pre_L1->val;
                    printf("1-asa:%d\n",cur->val);
                    pre_L1 = pre_L1->next;
                }else{    // l2 值 比 l1 值小 
                    cur->val = pre_L2->val;
                    printf("2-asa:%d\n",cur->val);
                    pre_L2 = pre_L2->next;            
                }
            }else{ // L2 结束 
                cur->val = pre_L1->val;
                // printf("3-asa:%d\n",cur->val);
                pre_L1 = pre_L1->next;
            } 
        }else{ // l2 长 
            cur->val = pre_L2->val;
            // printf("4-asa:%d\n",cur->val);
            pre_L2 = pre_L2->next;
        }
        cur->next = NULL;
    }
    return res->next;   
}
/*
int main(){
	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
	int i = 1;
	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	pre_L1 = l1;
	pre_L2 = l2;
	for(i=0; i< 10; i++){
		pre_L1->val = i;
		if (i!=9){
			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        	pre_L1 = pre_L1->next;
		}else{
			pre_L1->next = NULL;
		}
	}
	for(i=1; i< 10; i++){
		pre_L2->val = i*i;
		if (i!=9){
			pre_L2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        	pre_L2 = pre_L2->next;
		}else{
			pre_L2->next = NULL;
		}
	}
	printList(l1);
	printList(l2);
	l3 = mergeTwoLists(l1, l2);
	printList(l3);
}*/



