#nalazi trocifren br ABC tkd ABC/(A+B+C) je minimalan i A, B, C razl brojevi

import constraint

problem = constraint.Problem()

problem.addVariable('A', range(1,10))
problem.addVariable('B', range(10))
problem.addVariable('C', range(10))

problem.addConstraint(constraint.AllDifferentConstraint())
resenja = problem.getSolutions()

min_kolicnik = 5345345
min_resenje = {}
for resenje in resenja:
	a = resenje['A']
	b = resenje['B']
	c = resenje['C']
	kolicnik = (a*100 + b*10 + c) / (a+b+c)
	if kolicnik < min_kolicnik:
		min_kolicnik = kolicnik
		min_resenje = resenje
		
print(min_resenje['A']*100 + min_resenje['B']*10 + min_resenje['C'])
