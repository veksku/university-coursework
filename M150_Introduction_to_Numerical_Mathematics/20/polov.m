function x = polov(tol)
tablica;
a=X(1);
b=X(end);
if (funk(a)*funk(b)>0)
    error('Funkcija ne menja znak na posmatranom segmentu')
end
if funk(a)==0
    x=a;
else
    if funk(b)==0
        x=b;
    end
end
if (funk(a)~=0 && funk(b)~=0)
    iter=0;
    while(abs(a-b)>tol)
        x=(a+b)/2;
        iter=iter+1;
        if funk(x)==0
            break
        else
            if funk(a)*funk(x)<0
                b=x;
            else 
                a=x;
            end
        end
    end
    x=(a+b)/2;
end