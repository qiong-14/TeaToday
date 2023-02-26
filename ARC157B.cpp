#include <stdio.h>

#define N_MAX 200000

int solve(int N, int K, char S[])
{
	int i, x = 0;
	for (i = 0; i < N; i++) if (S[i] == 'X') x++;
	if (K > x) {
		for (i = 0; i < N; i++) S[i] = (S[i] == 'X')? 'Y': 'X';
		return solve(N, N - K, S);
	}
	if (x == N) {
		if (K <= 1) return 0;
		else return K - 1;
	}
	
	int j, xxx_num[N_MAX + 1] = {}, ans = 0;
	for (i = 0; i < N; i++) if (S[i] == 'Y') break;
	for (; i < N; i = j) {
		for (j = i + 1; j < N; j++) if (S[j] == 'Y') break;
		if (S[j] == 'Y') xxx_num[j-i-1]++;
	}
	for (i = 1; i <= N && K > 0; i++) {
		while (xxx_num[i] > 0 && K > 0) {
			if (i <= K) {
				ans += i + 1;
				K -= i;
				xxx_num[i]--;
			} else {
				ans += K;
				K = 0;
			}
		}
	}
	if (K > 0) ans += K;
	for (i = 0; i < N; i++) if (S[i] == 'Y' && S[i+1] == 'Y') ans++;
	return ans;
}

int main()
{
	int N, K;
	char S[N_MAX + 1];
	scanf("%d %d", &N, &K);
	scanf("%s", S);
	printf("%d\n", solve(N, K, S));
	fflush(stdout);
	return 0;
}