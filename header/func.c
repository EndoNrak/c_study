#include <math.h>

// 内部関数のプロトタイプ宣言（関数定義の順序次第では省略してもよい）
double Average(double x[], int n);
double StdDev(double x[], int n);
double Sum(double x[], int n);

/* 合計を計算する関数 */
double Sum(double x[], int n){
	int    i;
	double s = 0.0;

	for (i = 0; i < n; i++) {
		s += x[i];
	}
	return (s);
}

/* 平均を計算する関数 */
double Average(double x[], int n)
{
	return (Sum(x, n)/n);
}

/* 標準偏差を計算する関数 */
double StdDev(double x[], int n)
{
	int    i;
	double a, d, s = 0.0;

	a = Average(x, n);	// 平均

	for (i = 0; i < n; i++) {
		d = x[i] - a;		 // 偏差
		s += d*d;		 // 偏差自乗和
	}
	return (sqrt(s/n));
}