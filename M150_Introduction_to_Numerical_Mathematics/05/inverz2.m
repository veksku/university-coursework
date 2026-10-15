function x=inverz2(y)
[X1, Y1]=tablica();
disp('Tablica:')
disp([X1;Y1])

%funkcija sortrows(A,n) sortira matricu A po n-toj koloni
%       [Y1' X1']=[y_1 x_1
%                  y_2 x_2
%                  ... 
%                      
%                  y_n x_n]
%
inv_tablica=sortrows([Y1' X1'],1);  %sortiramo po prvoj koloni

Y=inv_tablica(:,1)';
X=inv_tablica(:,2)';

disp('Invertovana tablica:')
disp([Y;X])

x=0;

n=length(X);

for i=1:n
    p=1;
    for j=1:n
        if i~=j 
            p=p*(y-Y(j))/(Y(i)-Y(j));
        end
    end
    x=x+p*X(i);
end
