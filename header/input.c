#include <stdio.h>
#include <stdlib.h>

// グローバル変数の定義
int  data_error = 0;	// 入力データのエラーコード

/* ファイルからデータを入力する関数 */
int ReadData(FILE *fp, double x[], int size){
	int	n, c;
	for (n = 0; n < size; n++) {
		c = fscanf(fp, "%lf", &x[n]);
		if (c != 1) break;
	}
	if (c == 0) data_error = 1;		// 異常なデータ
	else if (n == 0) data_error = 2;	// データなし
	else if (n >= size) data_error = 3;	// 配列サイズ不足
	return (n);
}

/* 入力データのエラー処理 */
void DataError(int n){
	char *msg;

	switch (data_error) {
	case 1: msg = "data is strange"; break;
	case 2: msg = "there is no data"; break;
	case 3: msg = "it is too big data"; break;
	default: msg = "anyway, error";
	}
	fprintf(stderr, "data %d ：%s\n", n, msg);
	exit (EXIT_FAILURE);
}