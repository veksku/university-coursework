//rastuce

void merge_sort(double *niz, int leva, int desna)
{
	if (leva >= desna)
		return;
		
	int sr = (leva + desna)/2;
	
	merge_sort(niz, leva, sr);
	merge_sort(niz, sr+1, desna);
	
	//spajanje u sortiran niz
	double *pom;
	
	pom = malloc((desna - leva + 1)*sizeof(double));
	if (pom == NULL)
		greska();
	
	int i = 0; //brojac za pom
	int j = leva; //brojac levi deo 	
	int k = sr+1; //brojac za desni deo
	
	while (j <= sr && k <= desna){
		if (niz[j] < niz[k]){
			pom[i] = niz[j];
			j++;
		}
		else{
			pom[i] = niz[k];
			k++;
		}
		i++;
	}
	while (j<= sr){
		pom[i] = niz[j];
		j++;
		i++;
	}
	while (k <= desna){
		pom[i] = niz[k];
		k++;
		i++;
	}
	
	//prepisujemo pom u niz
	int dim = i;
	for(i=0; i<dim; i++)
		niz[leva+i] = pom[i];
		
	//na kraju f-je
	free(pom);
}
