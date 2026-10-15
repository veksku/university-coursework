function t=tablicaCheck()
tablica;

n=length(X);
r=1;   %Indikator za X
m=1;   %Indikator za Y
for i=1:n-1
    if X(i+1)<X(i)
       r=0;
       disp('Niz X nije rastuci.');
        break;
    end
end
i=1;
if Y(2)>Y(1)
    while(i<n && Y(i+1)>Y(i))
        i=i+1;
    end
else if Y(2)<Y(1)
        while(i<n && Y(i+1)<Y(i))
            i=i+1;
        end
    end
end
if i<n
    m=0;
    disp('Niz Y nije monoton');
end
t=m && r;