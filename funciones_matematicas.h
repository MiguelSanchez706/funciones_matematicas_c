//Biblioteca matematica de pruebas

double vabs(double x);

double calc_exp(double x);
double calc_cos(double x);

double potencia(double x, int n);
double raiz_bis(double x,int n);



double vabs(double x) {
	
	if (x<0) x*=-1;
	return x;
}

double calc_exp(double x) {
	double an,sn,epsilon=1e-8;
	int n=1;
	an=x;
	sn=1+an;
	
	while(vabs(an)/(1+vabs(sn)) > epsilon) {
		n++;
		an*=(x/n);
		sn+=an;
	}
	
	return sn;
}

double calc_cos(double x) {
	double an,sn,epsilon=1e-8,xx;
	int n2;
	xx=x*x;
	an=-xx/2.0;
	sn=1.0+an;
	n2=2;
	while(vabs(an)/(1+vabs(sn)) > epsilon) {
		n2+=2;
		an*=-xx/(n2*(n2-1.0));
		sn+=an;
	}
	//printf("numero de iteraciones : %d\n",n2/2);
	
	return sn;
}

double potencia(double x, int n) {
	int i;
	double pot = 1;
	for(i=1; i<=n; i++)	pot*=x;
	
	return pot;
}

double raiz_bis(double x,int n) {
	if (x < 0) return -1;
	if (x == 0) return 0;

	double liminf,limsup,medio,epsilon=1e-8,pot;

	if(x > 1) {
		liminf = 1;
		limsup = x;
	}
	else {
		liminf = x;
		limsup = 1;
	}
		
	do {
		medio = (limsup+liminf)/2;

		pot = potencia(medio,n);

		if (pot < x)	liminf = medio;
		else	limsup = medio;
	
	}while(vabs(pot-x) > epsilon);

	return medio;
}







