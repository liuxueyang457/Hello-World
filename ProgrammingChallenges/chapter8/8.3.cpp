#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <functional>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cassert>
#include <ctime>
#include <iterator>
const int INF = 0x3f3f3f3f;
const int dir[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
using namespace std;
const int MAXN = 1000;
bool is_a_solution(int k, int n) {
	return (k == n);
}
void process_solution(int a[], int k) {
	for (int i = 1; i <= k; ++i) {
		printf(" %d", a[i]);
	}
	printf("\n");
}
void construct_candidates(int a[], int k, int n, int c[], int &ncandidates) {
	bool in_perm[MAXN];
	int i;
	for (i = 1; i <= n; ++i) in_perm[i] = false;
	for (i = 1; i < k; ++i) in_perm[a[i]] = true;
	ncandidates = 0;
	for (i = 1; i <= n; ++i) {
		if (!in_perm[i]) {
			c[ncandidates] = i;
			++ncandidates;
		}
	}
}
void backtrack(int a[], int k, int n) {
	int c[MAXN];
	int ncandidates;
	if (is_a_solution(k, n)) {
		process_solution(a, k);
	}
	else {
		++k;
		construct_candidates(a, k, n, c, ncandidates);
		int i;
		for (i = 0; i < ncandidates; ++i) {
			a[k] = c[i];
			backtrack(a, k, n);
		}
	}
}
int main ( int argc, char *argv[] )
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	while (~scanf("%d", &n)) {
		int a[MAXN];
		backtrack(a, 0, n);
	}
		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
