/*
ID: zypz4571
LANG: C++
TASK: 8.1.cpp
									Intput n.
									Then generate subsets of 1...n
01/06/14 21:12:11
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
void construct_candidates(int a[], int c[], int &candidates, int k) {
	c[0] = 1;
	c[1] = 0;
	candidates = 2;
	return;
}
bool is_a_solution(int k, int n) {
	return (k == n);
}
void process_solution(int a[], int n) {
	for (int i = 1; i <= n; ++i) {
		if (a[i]) {
			cout << " " << i;
		}
	}
	cout << endl;
	return;
}
void backtrack(int a[], int n, int k) {
	int c[MAXN];
	int candidates;
	if (is_a_solution(k, n)) {
		process_solution(a, n);
	}
	else {
		++k;
		construct_candidates(a, c, candidates, k);
		for (int i = 0; i < candidates; ++i) {
			a[k] = c[i];
			backtrack(a, n, k);
		}
	}
	return;
}
void generate_subsets(int n, int k) {
	int a[MAXN];
	backtrack(a, n, k);
}
int main ( int argc, char *argv[] )
{
#ifndef ONLINE_JUDGE
//freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int n;
	while (cin>>n) {
		generate_subsets(n, 0);
	}
	
		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


