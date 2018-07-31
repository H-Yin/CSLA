/* 
	7. Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

int reverse(int x) {
	int flag = 0;
	int MAX = (1 << 31) - 1;
	long res = 0;

	if (x < 0){
		flag = 1;
		x = 0 - x;
	}

	while (x > 0){
		res = res * 10 + x % 10;
		x = x / 10;
	}
	// ÅĞ¶ÏÒç³ö
	if ((flag == 0 && res > MAX) || (flag == 1 && res - 1 > MAX)){
		return 0;
	}

	return (int)(flag ? 0 - res : res);

}