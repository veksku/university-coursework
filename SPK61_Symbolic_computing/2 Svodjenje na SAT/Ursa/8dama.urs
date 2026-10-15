nDim=8;
bDomain= true;
bNoCapture= true;

for(ni=0; ni<nDim; ni++){
	bDomain &&= (n[ni]<nDim); // sve dame na tabli
	for(nj=ni+1; nj<nDim; nj++) // nenapadanje
		bNoCapture &&= n[ni]!=n[nj] && ni+n[nj]!=nj+n[ni] && ni+n[ni]!=nj+n[nj];
}

assert_all(bDomain && bNoCapture);
