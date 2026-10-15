void merge(int *niz, int leva, int desna)
{
	if(leva >= desna)
		return;
		
	int sr = leva+(desna-leva)/2;

	merge(niz, leva, sr);
	merge(niz, sr+1, desna);
	
	int *pom;
	
	int i=0; //brojac za pom
	int j=leva; //brojac za levi
	int k=sr+1; //brojac za desni
	
	while(j<= sr || k<= desna){
		if(niz[j]<niz[k]){
			pom[i]=niz[j];
			j++;
		}
		else{
			pom[i]=niz[k];
			k++;
		}
		i++;
	}
	
	while(j<=sr){
		pom[i]=niz[j];
		j++;
		i++;
	}
	
	while(k<=desna){
		pom[i]=niz[k];
		k++;
		i++;
	}
	
	
	int dim = i;
	for(i=0;i<dim; i++)
		niz[leva+i]=pom[i];
		
	free(pom);
}
