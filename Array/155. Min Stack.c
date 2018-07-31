/*
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A155A
#ifdef A155A

// 链栈
//typedef struct node
//{
//	int value;
//	struct node *next;
//} Node;
//
//typedef struct {
//	Node mainStack;
//	Node minStack;
//} MinStack;
//
///** initialize your data structure here. */
//MinStack* minStackCreate(int maxSize) {
//	MinStack* stack = NULL;
//	stack = (MinStack*)malloc(sizeof(MinStack));
//	if (stack == NULL)
//	{
//		return NULL;
//	}
//	stack->mainStack.next = NULL;
//	stack->minStack.next = NULL;
//	return stack;
//}
//
//void minStackPush(MinStack* obj, int x) {
//	int min = minStackGetMin(obj);
//	Node *temp = (Node*)malloc(sizeof(Node));
//	temp->value = x;
//	temp->next = obj->mainStack.next;
//	obj->mainStack.next = temp;
//	if (x <= min)
//	{
//		temp = (Node*)malloc(sizeof(Node));
//		temp->value = x;
//		temp->next = obj->minStack.next;
//		obj->minStack.next = temp;
//	}
//}
//
//void minStackPop(MinStack* obj) {
//	int x, min;
//	Node *temp = obj->mainStack.next;
//	x = temp->value;
//	min = minStackGetMin(obj);
//	obj->mainStack.next = temp->next;
//	free(temp);
//	if (x == min)
//	{
//		temp = obj->minStack.next;
//		obj->minStack.next = temp->next;
//		free(temp);
//	}
//}
//
//int minStackTop(MinStack* obj) {
//	Node *temp = obj->mainStack.next;
//	if (temp != NULL)
//	{
//		return temp->value;
//	}
//	return 2147483647;
//}
//
//int minStackGetMin(MinStack* obj) {
//	Node *temp = obj->minStack.next;
//	if (temp != NULL)
//	{
//		return temp->value;
//	}
//	return 2147483647;
//}
//
//void minStackFree(MinStack* obj) {
//	Node *temp = NULL;
//	temp = obj->mainStack.next;
//	while (temp != NULL)
//	{
//		obj->mainStack.next = temp->next;
//		free(temp);
//		temp = obj->mainStack.next;
//	}
//	temp = obj->minStack.next;
//	while (temp != NULL)
//	{
//		obj->minStack.next = temp->next;
//		free(temp);
//		temp = obj->minStack.next;
//	}
//	free(obj);
//}
// // 双栈（顺序栈）
//typedef struct {
//	int *nums; // 数据栈
//	int *mins; // 最小值栈
//	int len; // 数据栈顶位置
//	int minLen; // 最小值栈栈顶位置
//} MinStack;
//
///** initialize your data structure here. */
//MinStack* minStackCreate(int maxSize) {
//	MinStack* stack = NULL;
//	stack = (MinStack*)malloc(sizeof(MinStack));
//	if (stack == NULL)
//	{
//		return NULL;
//	}
//	// 初始化双栈
//	stack->nums = (int*)malloc(sizeof(int)*maxSize);
//	stack->mins = (int*)malloc(sizeof(int)*maxSize);
//	stack->len = -1;
//	stack->minLen = -1;
//	return stack;
//}
//
//void minStackPush(MinStack* obj, int x) {
//	int min = minStackGetMin(obj);
//	obj->nums[++(obj->len)] = x;
//	if (x <= min)
//	{
//		obj->mins[++(obj->minLen)] = x;
//	}
//}
//
//int minStackPop(MinStack* obj) {
//	if (obj->len < 0){
//		return INT_MAX;
//	}
//	int x = obj->nums[obj->len], min = minStackGetMin(obj);
//	if (x == min)
//	{
//		obj->minLen--;
//	}
//	obj->len--;
//	return x;
//}
//
//int minStackTop(MinStack* obj) {
//	if (obj->len >=0)
//	{
//		return obj->nums[obj->len];
//	}
//	return INT_MAX;
//}
//
//int minStackGetMin(MinStack* obj) {
//	if (obj->minLen >= 0){
//		return obj->mins[obj->minLen];
//	}
//	return INT_MAX;
//}
//
//void minStackFree(MinStack* obj) {
//	free(obj->nums);
//	free(obj->mins);
//	free(obj);
//}
// 单栈（顺序栈）
typedef struct {
	long *nums; // 数据栈
	long min; // 当前最小值
	int len; // 数据栈顶位置
} MinStack;

void printLongArray(long* nums, long numsSize)
{
	printf("[");
	for (int i = 0; i < numsSize; i++){
		printf("%ld, ", nums[i]);
	}
	printf("]\n");
}

MinStack* minStackCreate(int maxSize) {
	MinStack* stack = NULL;
	stack = (MinStack*)malloc(sizeof(MinStack));
	if (stack == NULL)
	{
		return NULL;
	}
	// 初始化数据栈
	stack->nums = (long*)malloc(sizeof(long)*maxSize);
	stack->min = INT_MAX;
	stack->len = -1;
	return stack;
}

void minStackPush(MinStack* obj, int x) {
	long min = minStackGetMin(obj);
	if (obj->len < 0){
		obj->nums[++(obj->len)] = 0;
	}
	else{
		obj->nums[++(obj->len)] = ((long)x - (long)min);
	}
	if (x <= min)
	{
		obj->min = x;
	}
	printLongArray(obj->nums, obj->len + 1);
	printf("0==> %d\n",obj->min);
}

int minStackPop(MinStack* obj) {
	if (obj->len < 0){
		return INT_MAX;
	}
	long x = obj->nums[obj->len--], min = minStackGetMin(obj);
	if (x < 0L)
	{
		obj->min = obj->min - x;
	}
	return x + min;
}

int minStackTop(MinStack* obj) {
	if (obj->len >= 0)
	{
		return obj->nums[obj->len] + obj->min;
	}
	return INT_MAX;
}

int minStackGetMin(MinStack* obj) {
	return obj->min;
}

void minStackFree(MinStack* obj) {
	free(obj->nums);
	free(obj);
}

int main(){
	int param_4;
	struct MinStack* obj = minStackCreate(10);
	minStackPush(obj,INT_MAX);
	minStackPush(obj, INT_MIN);
	printf("%d\n", minStackGetMin(obj));
	minStackPop(obj);
	printf("%d\n", minStackGetMin(obj));
	minStackFree(obj);
	return 0;
}

#endif