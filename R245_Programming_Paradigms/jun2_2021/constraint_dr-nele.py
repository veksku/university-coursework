#b: 9
#c: 19
#d: 6
#m: 4
#s: 2
#z: 8
#
#11800 dinara
#
#cena:
#b: 130 => 9
#c: 800 => 14
#d: 150 => 6  !
#m: 370 => 4  !
#s: 490 => 2  !
#z: 150 => 9
#
#proteina < 100g, am kis < 200g
#
#protein:
#b: 15 => 6 !
#c: 11 => 9
#d: 10 => 6
#m: 22 => 4
#s: 1  => 2
#z: 13 => 7 !
#
#am kis:
#b: 33 => 6
#c: 31 => 6 !
#d: 20 => 6
#m: 18 => 4
#s: 21 => 2
#z: 16 => 8
#
#maksimizujemo hemoglobin
#
#hemoglobin:
#b: 92.5
#c: 155.5
#d: 79.6
#m: 156.2
#s: 413
#z: 137.7

import constraint

def ogranicenje_cena(b, c, d, m, s, z):
	return b*130 + c*800 + d*150 + m*370 + s*490 + z*150 <= 11800
	
def ogranicenje_proteina(b, c, d, m, s, z):
	return b*15 + c*11 + d*10 + m*22 + s*1 + z*13 <= 100
	
def ogranicenje_amkiselina(b, c, d, m, s, z):
	return b*33 + c*31 + d*20 + m*18 + s*21 + z*16 <= 200

problem = constraint.Problem()

problem.addVariable('b', range(0,7))
problem.addVariable('c', range(0,7))
problem.addVariable('d', range(0,7))
problem.addVariable('m', range(0,5))
problem.addVariable('s', range(0,3))
problem.addVariable('z', range(0,8))

problem.addConstraint(ogranicenje_cena, 'bcdmsz')
problem.addConstraint(ogranicenje_proteina, 'bcdmsz')
problem.addConstraint(ogranicenje_amkiselina, 'bcdmsz')


resenja = problem.getSolutions()

max_hemoglobin = 0

for r in resenja:
	hemoglobin = r['b']*92.5 + r['c']*155.5 + r['d']*79.6 + r['m']*156.2 + r['s']*413 + r['z']*137.7
	if hemoglobin > max_hemoglobin:
		br_b = r['b']
		br_c = r['c']
		br_d = r['d']
		br_m = r['m']
		br_s = r['s']
		br_z = r['z']
		max_hemoglobin = hemoglobin
		
print(br_b, br_c, br_d, br_m, br_s, br_z)
print(round(max_hemoglobin,2))
