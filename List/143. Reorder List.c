/*
Given a singly linked list L: L0��L1������Ln-1��Ln,
reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2����

You must do this in-place without altering the nodes' values.
*/

#include <stdio.h>
#include <stdlib.h>
#include "MyList.h"

/*
//extension: nodes in even position change from tail to head
void reorderList(struct ListNode* head) {
	struct ListNode oddList, evenList;
	struct ListNode *cur, *next, *last;
	struct ListNode *oddnext = &oddList;
	int count = 1;
	cur = head;
	oddList.next = NULL;
	evenList.next = NULL;

	for (count = 1; cur != NULL; count++)
	{
		next = cur->next;
		if (count % 2)
		{
			oddnext->next = cur;
			cur->next = NULL;
			oddnext = oddnext->next;
		}
		else{
			cur->next = evenList.next;
			evenList.next = cur;
		}
		cur = next;
	}
	printList(oddList.next);
	printList(evenList.next);
	cur = head;
	oddnext = evenList.next;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = oddnext;
		last = oddnext->next;
		oddnext->next = next;
		cur = next;
		oddnext = last;
	}
}*/


void reorderList(struct ListNode* head) {
	struct ListNode evenList; // ��Ҫ��������λ�õ�����
	struct ListNode *cur, *next, *last, *even_cur, *even_next;
	int count = 0, num = 0;
	
	if (!head){
		return NULL;
	}
	evenList.next = NULL;
	// ��ȡ������
	cur = head;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	// ����ǰ(n/2-1)���ڵ㣬�ҵ�Ҫ����������׽ڵ�
	last = head;
	num = (count+1) / 2;
	while (num-- > 1)
	{
		last = last->next;
	}
	// �ֳ���������
	even_cur = last->next;
	last->next = NULL;
	// ����ʣ�µ� n/2 ���ڵ�
	while (even_cur != NULL){
		even_next = even_cur->next;
		even_cur->next = evenList.next;
		evenList.next = even_cur;
		even_cur = even_next;
	}
	// �����������ٲ��뵽ԭ������
	cur = head;
	even_cur = evenList.next;
	while (even_cur != NULL)
	{
		next = cur->next;
		even_next = even_cur->next;
		cur->next = even_cur;
		even_cur->next = next;
		cur = next;
		even_cur = even_next;
	}
}


#ifdef A143
int main(){
	int a[] = { 1, 2, 3, 4,5,6};
	struct ListNode* head = createList(a, 6);
	printList(head);
	reorderList(head);
	printList(head);
	getchar();
	return 0;
}
#endif