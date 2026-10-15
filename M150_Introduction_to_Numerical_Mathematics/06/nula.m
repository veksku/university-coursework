function nula(a,b,n)
[c,d]=promenaZnaka(a,b,n);
funkcija;
% Nakon tabeliranja na segmentu [c,d] nula ce biti na kraju tablice

[X1,Y1]=tablica(c,d,n);
kr=zeros(n,3);
kr(1:n-1,1)=diff(Y1);
for j=2:3
  for  i=1:n-j
      kr(i,j)=kr(i+1,j-1)-kr(i,j-1);
  end
end
disp([X1' Y1' kr])
% ODGOVARAJUCA ITERATIVNA FORMULA
% q =(  y-Y(n)-q*(q+1)*kRazlike(n-2,2)-
%     -q*(q+1)*(q+2)*kRazlike(n-3,3))/kRazlike(n-1,1)

q0=0;
q1=(-Y1(n)-q0*(q0+1)*kr(n-2,2)/2-q0*(q0+1)*(q0+2)*kr(n-3,3)/6)/kr(n-1,1);
Q=[q0 q1];
while(abs(q0-q1)>=1e-4)
    q0=q1;
q1=(-Y1(n)-q0*(q0+1)*kr(n-2,2)/2-q0*(q0+1)*(q0+2)*kr(n-3,3)/6)/kr(n-1,1);
Q=[Q q1]; % U Q upisujemo svako q_i iz iterativnog procesa
end
disp('Nula funkcije je: ');
x = X1(end)+Q(end)*(X1(2)-X1(1));
disp(x);
disp('iterativni niz q je: ');
disp(Q');

