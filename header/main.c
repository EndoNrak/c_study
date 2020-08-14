/****************************************************
 統計処理プログラム
  実数データを標準入力し，平均と標準偏差を表示する．
  参考URL "https://www.kushiro-ct.ac.jp/yanagawa/ex-2015/1-tg/05/index.html"
****************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000	// データ配列の最大サイズ

// 外部変数の型宣言
extern int  data_error;

// 外部関数のプロトタイプ宣言（extern は省略可）
extern double Average(double x[], int n);
extern double StdDev(double x[], int n);
extern int ReadData(FILE *fp, double x[], int size);
extern void DataError(int n);
				// 行末のセミコロン「;」忘れやすい
int main(){
	double x[SIZE];
	int	n;
	char file_name[] = "header/data.txt";
	FILE *fp;

	/* ファイルオープン */
    if ((fp = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "%s\n", "error: can't read file.");
        return EXIT_FAILURE;
    }
	n = ReadData(fp, x, SIZE);
	if (data_error != 0) DataError(n);

	printf("average：%f\n", Average(x, n));
	printf("standard deviation：%f\n", StdDev(x, n));

	return (EXIT_SUCCESS);
}