/*
657. Judge Route Circle
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A657
#ifdef A657

bool judgeCircle(char* moves) {
	int x=0, y=0;
	char *p = moves;
	while (*p != '\0'){
		switch (*p)
		{
		case 'U':y++; break;
		case 'D':y--; break;
		case 'L':x--; break;
		case 'R':x++; break;
		default:break;
		}
		p++;
	}
	if (x == 0 && y == 0){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	printf("%d", judgeCircle("URLD"));
	getchar();
	return 0;
}

#endif