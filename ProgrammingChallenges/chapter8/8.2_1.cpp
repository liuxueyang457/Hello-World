/*
ID: zypz4571
LANG: C++
TASK: 8.2_1.cpp
																Input n.
																Then output the permutatinos of 1...n.
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
bool is_a_solution(int k, int n) {
	return (k == n);
}
void process_solution(int a[], int n) {
	for (int i = 1; i <= n; ++i) {
		cout << a[i];
	}
	cout << endl;
	return;
}
void construct_candidate(int a[], int c[], int k, int n, int &candidates) {
	bool in_perm[MAXN];
	int i;
	for (i = 1; i <= n; ++i) in_perm[i] = false;
	for (i = 1; i < k; ++i) in_perm[a[i]] = true;
	candidates = 0;
	for (i = 1; i <= n; ++i) {
		if (!in_perm[i]) {
			c[candidates++] = i;
		}
	}
	return;
}
void backtrack(int a[], int k, int n) {
	int c[MAXN];
	int candidates;
	if (is_a_solution(k, n)) {
		process_solution(a, n);
	}
	else {
		++k;
		construct_candidate(a, c, k, n, candidates);
		for (int i = 0; i < candidates; ++i) {
			a[k] = c[i];
			backtrack(a, k, n);
		}
	}
	return;
}
void generate_premutations(int n) {
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
		generate_premutations(n);
	}
	
		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


