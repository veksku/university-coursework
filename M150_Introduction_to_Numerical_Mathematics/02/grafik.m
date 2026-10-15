function grafik(x,a,b,n)
funkcija;
[L,y]=Lagr1b(x,a,b,n);
xx=linspace(a,b,100);
plot(xx,f(xx),xx,polyval(L,xx));
legend('Funkcija','Interpolacioni polinom')
