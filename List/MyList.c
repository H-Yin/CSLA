#include "MyList.h"
#include <stdlib.h>

void printList(struct ListNode* L){
	struct ListNode* pre_L = L;
	while (pre_L){
		printf("%d->", pre_L->val);
		pre_L = pre_L->next;
	}
	printf("\n");
}

struct ListNode* createList(int * nodeArray, int nodeSize){
	struct ListNode L1, *pre_L1 = &L1, *temp;
	int i;
	for (i = 0; i< nodeSize; i++){
		temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->val = nodeArray[i];
		temp->next = NULL;
		pre_L1->next = temp;
		pre_L1 = pre_L1->next;
	}
	return L1.next;
}

void printRandomList(struct RandomListNode* L){
	struct RandomListNode* pre_L = L;
	while (pre_L){
		printf("%d->", pre_L->label);
		pre_L = pre_L->next;
	}
	printf("------\n");
}