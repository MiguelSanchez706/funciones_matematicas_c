int mcd(int p,int q);
int mcdv(int *v,int n);
int menor_div(int n);
int primo(int n);
int fact_primos(int n, int *fp, int *nf, int nfmax);
int desc_can(int n, int *fp, int *pots, int *nfd, int nfmax );

int mcd(int p, int q) {
    if (p==0 && q == 0) return 0;
    if (p<0) p*=-1;
    if (q<0) q*=-1;
    if (p==0) return q;
    if (q==0) return p;

    int c,r;
    do {
        c = p/q;
        r = p%q;
        p = q;
        q = r;
    }while(r != 0);

    return p;
}

int mcdv(int *v,int n) {
	if(n<=0) return -1;
	
	if(n==2) return mcd(*v,*(v+1));
	else return mcd(*v,mcdv(v+1,n-1)); 
}

int menor_div(int n){
	int mdiv,primo=1;
	
	for(mdiv=2;mdiv*mdiv<=n;mdiv++){
		if(!(n%mdiv)) {
			primo=0;
			break;
		}
	}
	
	if(primo) return n;
	else return mdiv;
}

int primo(int n) {
	if (n == menor_div(n)) return 1;
	return 0;
}

int fact_primos(int n, int *fp, int *nf, int nfmax) {
	if (n<=1) {
		*nf = 0;
		return 0;
	}
	
	*nf = 0;
	do {
		if (*nf > nfmax) {
			*nf = -1;
			return 0;
		}
		*fp = menor_div(n);
		n/=*fp;
		(*nf)++;
		fp++;
	}while(n != 1 );
	
	return 1;
}

int desc_can(int n, int *fp, int *pots, int *nfd, int nfmax ) {
	if (n<=1) {
		*nfd = 0;
		return 0;
	}
	int prim,primant;
	
	*nfd = 0;
	*fp = 1;
	*pots = 1;
	fp++;
	do {
		if (*nfd > nfmax) {
			*nfd = -1;
			return 0;
		}
		
		primant = *(fp-1);
		prim = menor_div(n);
		if(prim != primant) {
			pots ++;
			*fp = prim;
			*pots = 1;
			(*nfd)++;
			fp++;
		}
		else {
			(*pots)++;
		}
		
		n/=prim;
	}while(n != 1);
	
	return 1;	
}
