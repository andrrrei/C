#include <stdio.h>
#include <stdlib.h>


void matr(int m, int n)
{
	int arr[256][256];
	int k, p, q, c, d;
	k = 1;
	c = 0;
	d = 0;
	p = n;
	q = m;
	while (k <= m * n)
	{
		for (int i = c; i < p; i++) {
			arr[c][i] = k;
			k++;
		}
		c++;
		for (int i = c; i < q; i++) {
			arr[i][p-1] = k;
			k++;
		}
		p--;
		for (int i = p; i > d; i--) {
			arr[q-1][i-1] = k;
			k++;
		}
		q--;
		for (int i = q; i > c; i--) {
			arr[i-1][d] = k;
			k++;
		}
		d++;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", arr[i][j]);
			if (arr[i][j] < 10) {
			    printf("%s", "   ");
			}
			else if (arr[i][j] >= 10 && arr[i][j] < 100) {
			    printf("%s", "  ");
			}
			else {
			    printf("%c", ' ');
			}
		}
		printf("%c", '\n');
	}
}


int main() {

	int a, b;
	printf("%s\n", "Enter the size of the matrix");
	printf("%s", "M: ");
	scanf("%d", &a);
	printf("%s", "N: ");
	scanf("%d", &b);

	matr(a, b);
}