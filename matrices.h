#include <stdio.h>

int lec_M(int m, int n, double A[][40]);
int esc_M(int m, int n, double A[][40]);
int prod_AB(int m, int n, int p, int q, double A[][40], double B[][40], double C[][40]);

int lec_M(int m, int n, double A[][40]) {
	int i,j;
	double *p;
	p = &A[0][0];
	if(n <= 0 || n > 40 || m <= 0 || m > 40) return 0;
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) scanf("%lf", p++);
		p = p+40-j;
	}
	
	return 1;
}

int esc_M(int m, int n, double A[][40]) {
	if(n <= 0 || n > 40 || m <= 0 || m > 40) {
		printf("Argumentos no validos");
		return 0;
	}
	
	int i,j;
	double *p;
	p = &A[0][0];
	
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) 	printf(" %.2lf ", *p++);
		p = p+40-j;
		printf("\n");
	}
	
	puts("\n");
	return 1;
}

int prod_AB(int m, int n, int p, int q, double A[][40], double B[][40], double C[][40]) {
	if (m<=0 || n<=0 || p<=0 || q<=0 || m>40 || n>40 || p>40 || q>40 || n!=p) return 0;
	
	int i,j,k;
	double s;
	
	for(i = 0; i < m; i++) {
		for (j = 0;j < q; j++) {
			s = 0.0;
			for (k = 0; k < n; k++)	s += A[i][k]*B[k][j];
			C[i][j] = s;
		}
	}
	
	return 1;
}


