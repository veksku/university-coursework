#masti < 500
#secer < 150
#
#b,p,j,m,v,n
#
#b: cena-30	  br-10		masti-30	secer-5
#p: cena-300	br-20		masti-10	secer-30
#j: cena-50 	br-7 		masti-150	secer-2
#m: cena-170 	br-5 		masti-32	secer-15
#v: cena-400 	br-3 		masti-3		secer-45
#n: cena-450	br-9		masti-15	secer-68
#
#ukupno para 1170
#po ceni:
#b<=10
#p<=3
#j<=7
#m<=5
#v<=2
#n<=2
#
#ukupno masti 499
#po mastima:
#b<=10
#p<=20
#j<=3
#m<=5
#v<=3
#n<=9
#
#ukupno secera 150
#po seceru:
#b<=10
#p<=5
#j<=7
#m<=5
#v<=3
#n<=2
#
#30*b + 300*p + 50*j + 170*m + 400*v + 450*n = 1170

import constraint

def o(b,p,j,m,v,n):
	if 30*b + 300*p + 50*j + 170*m + 400*v + 450*n <= 1170:
		return True
	else:
		return False

problem = constraint.Problem()

problem.addVariable('b', range(0,11))
problem.addVariable('p', range(0,4))
problem.addVariable('j', range(0,4))
problem.addVariable('m', range(0,6))
problem.addVariable('v', range(0,3))
problem.addVariable('n', range(0,3))

problem.addConstraint(o, 'bpjmvn')
resenja = problem.getSolutions()

max_protein = -1
b_count = -1
p_count = -1
j_count = -1
m_count = -1
v_count = -1
n_count = -1

for r in resenja:
	protein = r['b']*20 + r['p']*15 + r['j']*70 + r['m']*40 + r['v']*23 + r['n']*7
	if protein > max_protein:
		max_protein = protein
		b_count = r['b']
		p_count = r['p']
		j_count = r['j']
		m_count = r['m']
		v_count = r['v']
		n_count = r['n']
		
print(max_protein, b_count, p_count, j_count, m_count, v_count,)
