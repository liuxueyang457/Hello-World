#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main ( int argc, char *argv[] )
{
	double d, a, b, m; while (cin>>d>>a>>b) { while (!(fabs(a - b) < d || (m*m-2 < 1e-9))) { m = (a + b) / 2; if ((a * a - 2) * (m * m - 2) < 0) b = m; else a = m; } cout << m << endl; } return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
