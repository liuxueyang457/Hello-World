#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;
char map[10][10];
int n,m,Time,flag,aa,bb;
int dir[8] = {0,1,0,-1,1,0,-1,0};
int used[10][10];
int t;
void DFS(int a,int b)
{
	int x,y,i,d;
	if( flag == 1 )
		return ;
	if( t == Time && map[a][b] == 'D' )
	{
		flag = 1;
		return ;
	}
	d = abs(a-aa) + abs(b-bb);
	if( d + t > Time )
		return ;
	if( d % 2 != (Time-t) % 2 )
		return ;
	for(i=0; i<8 && !flag; i+=2)
	{
		x = a + dir[i];
		y = b + dir[i+1];
		if( x >= 0 && x < n && y >= 0 && y < m && !used[x][y] && map[x][y] != 'X' )
		{
			t++;
			used[x][y] = 1;
			DFS(x,y);
			t--;
			used[x][y] = 0;;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("zoj2110.cpp.txt", "r", stdin);
#endif
	int i,k,a,b;
	while( scanf("%d%d%d",&n,&m,&Time) && ( n || m || Time ) )
	{
		int wall = 0;
		for(k=0; k<n; k++)
		{
			scanf("%s",map[k]);
			for(i=0; i<m; i++)
			{
				if( map[k][i] == 'S' )
				{
					a = k;
					b = i;
				}
				if( map[k][i] == 'D' )
				{
					aa = k; 
					bb = i;
				}
				if( map[k][i] == 'X' )
					wall++;
			}
		}		
		if( n*m-wall-1 < Time || abs(a-aa) + abs(b-bb) > Time )
		{
			printf("NO\n");
			continue;
		}
		flag = t = 0;
		memset(used,0,sizeof(used));
		used[a][b] = 1;
			clock_t start = clock(), finish;
		DFS(a,b);
			finish = clock();
			printf("%lu\n", finish - start);
		if( flag == 1 )
			printf("YES\n");
		else
			printf("NO\n");
	}
return 0;
}
