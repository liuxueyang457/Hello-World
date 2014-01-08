/*
ID: zypz4571
LANG: C++
TASK: zoj1649.cpp
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
int N, M, b[200][200], sx0, sy0, X, Y;
char a[200][200];
typedef struct node {
	int x; int y;
}point;
queue<point> q; 
	void
BFS ( int x, int y )
{
	point tmp;
	tmp.x = x;
	tmp.y = y;
	q.push(tmp);
	while ( !q.empty() ) {
		point now = q.front();
		q.pop();
		int nowoft = b[now.x][now.y];
		for ( int i = 0; i < 4; ++i ) {
			int nextx = now.x + dir[i][0];
			int nexty = now.y + dir[i][1];
			if ( nextx < 0 || nextx >= N - 1 || nexty < 0 || nexty >= M - 1 ) {
				continue;
			}
			point next;
			next.x = nextx;
			next.y = nexty;
			if ( a[nextx][nexty] == '.' || a[nextx][nexty] == 'r' || a[nextx][nexty] == 'a') {
				if ( 1 + nowoft < b[nextx][nexty] ) {
					b[nextx][nexty] = 1 + nowoft;
					q.push(next);
				}
			}
			else if (a[nextx][nexty] == 'x') {
				if (2 + nowoft < b[nextx][nexty]) {
					b[nextx][nexty] = 2 + nowoft;
					q.push(next);
				}
			}
		}
	}
	return ;
}		/* -----  end of function   ----- */
int main ( int argc, char *argv[] )
{
#ifndef ONLINE_JUDGE
freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	while ( cin>>N>>M ) {
		for ( int i= 0; i < N; ++i ) {
			cin>>a[i];
			for ( int j = 0; j < M; ++j ) {
				if ( a[i][j] == 'r' ) {
					sx0 = i;
					sy0 = j;
				}
				else if (a[i][j] == 'a') {
					X = i;
					Y = j;
				}
				b[i][j] = INT_MAX;
			}
		}
		b[sx0][sy0] = 0;
		while ( !q.empty() ) {
			q.pop();
		}
		BFS(sx0, sy0);
		if ( b[X][Y] < INT_MAX ) {
			cout << b[X][Y] << endl;
		}
		else {
			cout << "Poor ANGEL has to stay in the prison all his life." << endl;
		}
	}
		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


