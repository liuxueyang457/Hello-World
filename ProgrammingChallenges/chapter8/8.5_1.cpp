/*
ID: zypz4571
LANG: C++
TASK: 8.5_1.cpp
													Input n.
													Output solutions of nQueens and the solution_count.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <deque>
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
int solution_count;
bool is_a_solution(int n, int k) {
	return (k == n);
}
void process_solution(int a[], int n) {
	++solution_count;
	for ( int i = 1; i <= n; ++i ) {
		cout << " " << a[i];
	}
	cout << endl;
	return;
}

	void
construct_candidates ( int a[], int c[], int n, int k, int &candidates )
{
	candidates = 0;
	for ( int i = 1; i <= n; ++i ) {
		bool legal_move = true;
		for ( int j = 1; j < k; ++j ) {
			if ( i == a[j] ) {
				legal_move = false; break;
			}
			if ( abs(j - k) == abs(a[j] - i) ) {
				legal_move = false; break;
			}
		}
		if ( legal_move ) {
			c[candidates++] = i;
		}
	}
	return ;
}		/* -----  end of function   ----- */
void backtrack(int a[], int k, int n) {
	int c[MAXN];
	int candidates;
	if (is_a_solution(n, k)) {
		process_solution(a, n);
	}
	else {
		++k;
		construct_candidates(a, c, n, k, candidates);
		for ( int i = 0; i < candidates; ++i ) {
			a[k] = c[i];
			backtrack(a, k, n);
		}
	}
	return;
}
void nqueens(int n) {
	int a[MAXN];
	backtrack(a, 0, n);
}
int main ( int argc, char *argv[] )
{
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int n;
	while (cin>>n) {
		solution_count = 0;
		nqueens(n);
		cout << "solution_count = " << solution_count << endl;
	}
		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


