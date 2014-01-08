
/*-----------------------------------------------------------------------------
 *  Input n.
 *  Output solutino_count of n-kQueens.
 *-----------------------------------------------------------------------------*/
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
long long int solution_count;
bool is_a_solution(int k, int nk) {
	return (k == nk);
}
void process_solution() {
	++solution_count;
}
void construct_candidates(int a[], int c[], int n, int k, int &ncandidates) {
	bool legal_move;
	ncandidates = 0;
	for (int i = 1; i <= n; ++i) {
		legal_move = true;
		for (int j = 1; j < k; ++j) {
			if (abs(j - k) == abs(a[j] - i)) {
				legal_move = false; break;
			}
		}
		if (legal_move) {
			c[ncandidates] = i;
			++ncandidates;
		}
	}
}
void backtrack(int a[], int n, int k, int nk) {
	int c[MAXN];
	int ncandidates;
	if (is_a_solution(k, nk)) {
		process_solution();
	}
	else {
		++k;
		construct_candidates(a, c, n, k, ncandidates);
		for (int i = 0; i < ncandidates; ++i) {
			a[k] = c[i];
			backtrack(a, n, k, nk);
		}
	}
}
int main ( int argc, char *argv[] )
{
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	int nk;
	while (~scanf("%d%d", &n, &nk)) {
		if ( !(n + nk) ) {
			break;
		}
		if ( nk > 2 * n - 1 ) {
			printf("0\n");
		}
		else {
			int a[MAXN];
			solution_count = 0;
			backtrack(a, n, 0, nk);
			printf("%lld\n", solution_count);
		}
	}
		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


