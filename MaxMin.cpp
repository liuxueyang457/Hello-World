/*
ID: zypz4571
LANG: C++
TASK: MaxMin.cpp
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
#define TypeName string
long long arrayInt[1000000+9];
TypeName arrayCha[1000000+9];
char tmp[1000000+9];
template<typename T>
void StartMaxMin(T *a, int n, T &Max, T &Min) {
	int i;
	Max = Min = a[1];
	for (i = 2; i <= n; ++i) {
		if (a[i] > Max) Max = a[i];
		if (a[i] < Min) Min = a[i];
	}
}
template<typename T>
void SecondMaxMin(T *a, int i, int j, T &Max, T &Min) {
	if (i == j) Max = Min = a[i];
	else if (i == j - 1) {
		if (a[i] < a[j]) {
			Max = a[j];
			Min = a[i];
		} else {
			Max = a[i];
			Min = a[j];
		}
	}
	else {
		int mid = (i + j) / 2;
		T gMax = a[i], gMin = a[i], hMax = a[j], hMin = a[j];
		SecondMaxMin(a, i, mid, gMax, gMin);
		SecondMaxMin(a, mid + 1, j, hMax, hMin);
		if (gMax > hMax) Max = gMax; else Max = hMax;
		if (gMin < hMin) Min = gMin; else Min = hMin;
	}
}
int main ( int argc, char *argv[] )
{
#ifndef ONLINE_JUDGE
freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n, _t = 1;
	while (cin>>n) {
		cout << "case " << _t << ": n = " << n << endl;
		++_t;
		for (int i = 1; i <= n; ++i) {
			cin >> arrayInt[i];
			sprintf(tmp, "%lld", arrayInt[i]);
			arrayCha[i] = (string)(tmp);
		}
		long long MaxInt = arrayInt[1], MinInt = arrayInt[1];
		TypeName MaxCha = arrayCha[1], MinCha = arrayCha[1];
		clock_t start, finish;
		double t1, t2, t3, t4;

		start = clock();
		StartMaxMin(arrayInt, n, MaxInt, MinInt);
		finish = clock();
		t1 = finish - start;
		cout << "StartMaxMin -> \nMax = " << MaxInt << " Min = " << MinInt << endl;
		cout << "Time used: " << t1 << endl;

		MaxInt = MinInt = arrayInt[1];
		start = clock();
		SecondMaxMin(arrayInt, 1, n, MaxInt, MinInt);
		finish = clock();
		t2 = finish - start;
		cout << "SecondMaxMin -> \nMax = " << MaxInt << " Min = " << MinInt << endl;
		cout << "Time used: " << t2 << endl;

		cout << "-----------------As for int numbers, Second/Start = " << t2 / t1 << endl;

		MaxCha = MinCha = arrayCha[1];
		start = clock();
		StartMaxMin(arrayCha, n, MaxCha, MinCha);
		finish = clock();
		t3 = finish - start;
		cout << "StartMaxMin -> \nMax = " << MaxCha << " Min = " << MinCha << endl;
		cout << "Time used: " << t3 << endl;

		MaxCha = MinCha = arrayCha[1];
		start = clock();
		SecondMaxMin(arrayCha, 1, n, MaxCha, MinCha);
		finish = clock();
		t4 = finish - start;
		cout << "SecondMaxMin -> \nMax = " << MaxCha << " Min = " << MinCha << endl;
		cout << "Time used: " << t4 << endl;
		cout << "-----------------As for strings, Second/Start = " << t4 / t3 << endl;
		cout << "\n\n";
	}
		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


