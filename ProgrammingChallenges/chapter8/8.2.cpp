#include <cstdio>
#include <cstdlib>
const int MAXN = 1000;
bool is_a_solution(int a[], int k, int n) {
	return (k == n);
}
void process_solution(int a[], int k) {
	int i;
	for (i = 1; i<= k; ++i) {
		if (a[i]) printf(" %d", i);
	}
	printf("\n");
}
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {
	c[0] = 1;
	c[1] = 0;
	*ncandidates = 2;
}
void backtrack(int a[], int k, int input) {
	int c[MAXN];
	int ncandidates;
	int i;
	if (is_a_solution(a, k, input))
		process_solution(a, k);
	else {
		++k;
		construct_candidates(a, k, input, c, &ncandidates);
		for (i = 0; i < ncandidates; ++i) {
			a[k] = c[i];
			backtrack(a, k, input);
		}
	}
}
void generate(int n) {
	int a[MAXN];
	backtrack(a, 0, n);
}
int main(void) {
	int n;
	while (~scanf("%d", &n)) {
		generate(n);
	}

	return 0;
}
