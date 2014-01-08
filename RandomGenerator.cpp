/*
ID: zypz4571
LANG: C++
TASK: RandomGenerator.cpp
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <iterator>
const int INF = 0x3f3f3f3f;
using namespace std;
int main ( int argc, char *argv[] )
{
	freopen("in.txt", "w", stdout);
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int _t = 10;
	while (_t--) {
		int n = rand() % 10000;
		cout << n << endl;
		for (int i = 0; i < n; ++i) {
			cout << rand() % INF;
			cout << " ";
		}
		cout << endl;
	}
		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


