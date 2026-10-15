import constraint

def o(T,W,O,F,U,R):
	if 2*(100*T + 10*W + O) == 1000*F + 100*O + 10*U + R:
		return True

problem = constraint.Problem()

problem.addVariables('WOUR', range(10))
problem.addVariables('TF', range(1,10))

problem.addConstraint(o, "TWOFUR")
problem.addConstraint(constraint.AllDifferentConstraint())

resenja = problem.getSolutions()

for r in resenja:
	print(str(r['T']) + str(r['W']) + str(r['O']) + " + " + str(r['T']) + str(r['W']) + str(r['O']) + " = " + str(r['F']) + str(r['O']) + str(r['U']) + str(r['R']))
