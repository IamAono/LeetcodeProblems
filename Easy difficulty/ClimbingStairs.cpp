class Solution {
public:
	int ways = 0;
	int fib(int N) {
		int f = 0;
		int s = 1;
		int a;
		if (N == 0) {
			return 0;
		}
		if (N == 1) {
			return 1;
		}
		for (int i = 2; i <= N; i++) {
			a = f + s;
			f = s;
			s = a;
		}
		return a;
	}
	int climbStairs(int n) {
		return fib(n + 1);
	}
};