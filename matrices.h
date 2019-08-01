#include <stdio.h>
#include <stdlib.h>

struct matriz {
	double *mt;
	int m,n;
	int listo,llena;
};

int asignar_matriz(struct matriz *p, int m1, int n1);
int lec_M(struct matriz *p);
int esc_M(struct matriz *p);
int prod_AB1(struct matriz A,struct matriz B,struct matriz *C);


int asignar_matriz(struct matriz *p, int m1, int n1) {
	if(n1 > 0 && m1 > 0){
		p->mt = (double *) malloc(m1*n1*sizeof(double));
		if(p->mt != NULL) {
			p->m = m1;
			p->n = n1;
			p->llena = 0;
			p->listo = 1;
			return 1;
		}
	}
	p->listo = 0;
	return 0;
	
}

int lec_M(struct matriz *p) {
	if(p->listo) {
		int i,j;
		double *mr;
		mr = p->mt;
		for(i = 0; i < p->m; i++) {
			for(j = 0; j < p->n; j++) scanf("%lf", mr++);
		}	
		p->llena = 1;
		return 1;
	}
	
	return 0;
}

int esc_M(struct matriz *p) {
	if(p->listo && p->llena) {
		int i,j;
		double *mr;
		mr = p->mt;
		for(i = 0; i < p->m; i++) {
			for(j = 0; j < p->n; j++) 	printf(" %.2lf ",*mr++);
			printf("\n");
		}
		return 1;
	}

	return 0;
}

int prod_AB1(struct matriz A,struct matriz B,struct matriz *C){
	if(A.listo && A.llena && B.listo && B.llena && A.n == B.m) {
		asignar_matriz(C,A.m,B.n);
		if(C->listo) {
			double *cij,*cmq,*ciq,*boj,*aio,*ain,*aik,*bkj;
			int m,q,n;
			n = A.n;
			m = A.m;
			q = B.n;
			cij = C->mt;
			printf("%p\n",cij);
			cmq = cij +m*q;
			aio = A.mt;
			
			while(cij < cmq) {
				ciq = cij+q;
				boj = B.mt;
				while(cij < ciq) {
					aik = aio;
					ain = aio + n;
					bkj = boj;
					*cij = 0.0;
					while(aik < ain) {
						*cij += (*aik++)*(*bkj);
						bkj += q;
					}
					cij++;
					boj++;
				}
				aio = ain;
			}
			
			C->llena = 1;
			return 1;
		}
		return 0;
	}



















}





