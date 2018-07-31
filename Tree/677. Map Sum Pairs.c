/*
677. Map Sum Pairs
Implement a MapSum class with insert, and sum methods.
For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.
For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A677
#ifdef A677

typedef struct {

} MapSum;

/** Initialize your data structure here. */
MapSum* mapSumCreate() {

}

void mapSumInsert(MapSum* obj, char* key, int val) {

}

int mapSumSum(MapSum* obj, char* prefix) {

}

void mapSumFree(MapSum* obj) {

}


int main(){
	/*
	struct MapSum* obj = mapSumCreate();
	mapSumInsert(obj, key, val);
	int param_2 = mapSumSum(obj, prefix);
	mapSumFree(obj);
	*/
	return 0;
}

#endif
