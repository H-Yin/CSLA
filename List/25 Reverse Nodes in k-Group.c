
/*

25. Reverse Nodes in k-Group


*/

#include<stdio.h>
#include<stdlib.h>
#include "MyList.h"
 //Definition for singly-linked list.

// non-inplace
// 时间： 最好：n 最差 ：2n 即 n<k
// 空间： n 
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode* pre = NULL, *tail = head;
	struct ListNode* new_head, *new_cur = NULL, *new_pre =NULL, *last_pre = NULL, *new_tail=NULL;
	new_head = (struct ListNode*)malloc(sizeof(struct ListNode)); 
	new_head->next = NULL;
	new_pre = new_head;
    int i = 0;
    while( tail ){
    	i = 0;
		last_pre = new_pre; // 记录最新的将要反转的group的首指针 
        while(i++<k && tail){ // 遍历 k 个 跳出 ，或者原数组结束
			// 申请新节点保存原节点值 
    		new_cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    		new_cur->val = tail->val;
    		// len(gruop_i) >= k 记录该group的尾指针，便于下一个group连接
			// len(gruop_i) < k 记录原链表该group的首指针，便于“回退” 
    		if (i == 1){
    			new_tail = new_cur;
    			pre = tail;
			}
			// 头插法  实现反转 
			new_cur->next = new_pre->next;
    		new_pre->next = new_cur;
    		// 遍历下一个 group 
			tail = tail->next;
		}
		// 最后一个 group 长度小于 k ,则“回退 ”
		if (!tail && i < k+1){
			// 从最后一个 group 回退 
			while(pre){
				last_pre->next->val = pre->val;
				pre = pre->next;
				last_pre = last_pre->next;
			}
		}
		//  跳过当前已经反转的group 
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
