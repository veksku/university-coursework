function t=tablicaCheck()
tablica;
r=all(diff(X)>0);
h=X(2)-X(1);
%ekv=all(diff(X)==h); Radi samo za celobrojne vrednosti koraka h!
ekv=all(abs(diff(X)-h)<=eps);
t=r&&ekv;
if t==1
    disp('Tablica je ekvidistantna i vektor X je dat u strogo rastucem poretku.')
else
    disp('Nisu ispunjeni uslovi zadatka!')
end