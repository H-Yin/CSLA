
/*

25. Reverse Nodes in k-Group


*/

#include<stdio.h>
#include<stdlib.h>
#include "MyList.h"
 //Definition for singly-linked list.

// non-inplace
// ʱ�䣺 ��ã�n ��� ��2n �� n<k
// �ռ䣺 n 
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode* pre = NULL, *tail = head;
	struct ListNode* new_head, *new_cur = NULL, *new_pre =NULL, *last_pre = NULL, *new_tail=NULL;
	new_head = (struct ListNode*)malloc(sizeof(struct ListNode)); 
	new_head->next = NULL;
	new_pre = new_head;
    int i = 0;
    while( tail ){
    	i = 0;
		last_pre = new_pre; // ��¼���µĽ�Ҫ��ת��group����ָ�� 
        while(i++<k && tail){ // ���� k �� ���� ������ԭ�������
			// �����½ڵ㱣��ԭ�ڵ�ֵ 
    		new_cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    		new_cur->val = tail->val;
    		// len(gruop_i) >= k ��¼��group��βָ�룬������һ��group����
			// len(gruop_i) < k ��¼ԭ�����group����ָ�룬���ڡ����ˡ� 
    		if (i == 1){
    			new_tail = new_cur;
    			pre = tail;
			}
			// ͷ�巨  ʵ�ַ�ת 
			new_cur->next = new_pre->next;
    		new_pre->next = new_cur;
    		// ������һ�� group 
			tail = tail->next;
		}
		// ���һ�� group ����С�� k ,�򡰻��� ��
		if (!tail && i < k+1){
			// �����һ�� group ���� 
			while(pre){
				last_pre->next->val = pre->val;
				pre = pre->next;
				last_pre = last_pre->next;
			}
		}
		//  ������ǰ�Ѿ���ת��group 
		new_pre = new_tail;
	}
	return new_head->next;
}


/*int main(){
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
	
	//for(i=5; i< 6; i++){
	//	pre_L2->val = i;
	//	if (i!=5){
	//		pre_L2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
 //       	pre_L2 = pre_L2->next;
	//	}else{
	//		pre_L2->next = NULL;
	//	}
	//}
	printList(l1);
	// printList(l2);
	l3 = reverseKGroup(l1,4);
	printList(l3);
}*/
