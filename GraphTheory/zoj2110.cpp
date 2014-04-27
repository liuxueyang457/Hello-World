/*
ID: zypz4571
LANG: C++
TASK: zoj2110.cpp
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
#include <climits>
const int INF = 0x3f3f3f3f;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
using namespace std;
int N, M, T, X, Y, wall, sx0, sy0;
char a[8][8];
bool success;
	void
DFS ( int x, int y , int t)
{
	if ( success ) {
		return;
	}
	if ( t == T && x == X && y == Y ) {
		success = true;
		return;
	}
	int minT = abs(x - X) + abs(y - Y);
	int tmp = T - t - minT;
	if ( (tmp < 0) || (tmp & 1) ) {
		return;
	}
	for ( int i = 0 ; i < 4; ++i ) {
		int x1 = x + dir[i][0], y1 = y + dir[i][1];
		if ( x1 >= 0 && x1 < N && y1 >= 0 && y1 < M && a[x1][y1] != 'X') { /* Be Careful N and M!  */
				a[x1][y1] = 'X';
				DFS(x1, y1, t + 1);
				if ( success ) { return; }
				a[x1][y1] = '.';
		}
	}
	return ;
}		/* -----  end of function   ----- */
int main ( int argc, char *argv[] )
{
#ifndef ONLINE_JUDGE
freopen("zoj2110.cpp.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	while (~scanf("%d%d%d", &N, &M, &T)){
		if ( !(N + M + T) ) { break; }
		wall = 0;
		success = false;
		for ( int i = 0; i < N; ++i ) {
			scanf("%s", a[i]);
			for ( int j = 0; j < M; ++j ) {
				if ( a[i][j] == 'D' ) {
					X = i;
					Y = j;
				}
				else if (a[i][j] == 'S') {
					sx0 = i;
					sy0 = j;
				}
				else if (a[i][j] == 'X') { ++wall; }
			}
		}
		if ( N * M - wall <= T || (abs(X-sx0)+abs(Y-sy0)>T)) {
			printf("NO\n");
			continue;
		}
		else {
			a[sx0][sy0] = 'X';
//			clock_t start = clock(), finish;
			DFS(sx0, sy0, 0);
//			finish = clock();
//			printf("%lu\n", finish - start);
		}
		if ( success ) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


