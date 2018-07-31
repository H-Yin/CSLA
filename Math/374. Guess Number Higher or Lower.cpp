/*
374. Guess Number Higher or Lower
*/
// #define A374
#ifdef A374
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int flag = 0;
		// 防止求和之后的溢出问题
		long num, left = 1, right = n;
		while (1){
			num = (left + right) / 2;
			flag = guess(num);
			if (flag == 0){
				return num;
			}
			else if (flag > 0){
				left = num + 1;
			}
			else{
				right = num - 1;
			}
		}
	}
};

#endif