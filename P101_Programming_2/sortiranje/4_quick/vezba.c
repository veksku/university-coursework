void razmeni (int *a, int *b)
{
	int pom= *a;
	*a=*b;
	*b=pom;
	
	return;
}

void qsort (int *niz, int leva, int desna)
{
	if (leva>=desna)
		return;
	
	int pivot = niz[leva];
	
	int i= leva+1;
	int j= desna;
	
	if(niz[i] > pivot && niz[j] <= pivot){
		razmeni(&niz[i],&niz[j]);
		i++;
		j--;
	}
	else{
		if (niz[i] <= pivot)
			i++;
		if(niz[j] > pivot)
			j--;
	}
	
	razmeni(&niz[leva], &niz[j]);
	qsort(niz, leva, j-1);
	qsort(niz, i, desna);
}
