# a b c
# d e f
# g h i

import constraint

def o(x,y,z):
	if x+y+z == 15:
		return True

problem = constraint.Problem()
problem.addVariables('abcdefghi', range(1,10))
problem.addConstraint(constraint.AllDifferentConstraint())

problem.addConstraint(o, "abc")
problem.addConstraint(o, "def")
problem.addConstraint(o, "ghi")

problem.addConstraint(o, "adg")
problem.addConstraint(o, "beh")
problem.addConstraint(o, "cfi")

problem.addConstraint(o, "aei")
problem.addConstraint(o, "ceg")

resenja = problem.getSolutions()
i = 0

for r in resenja:
	print("------")
	i=i+1
	print(str(r['a']) + " " + str(r['b']) + " " + str(r['c']))
	print(str(r['d']) + " " + str(r['e']) + " " + str(r['f']))
	print(str(r['g']) + " " + str(r['h']) + " " + str(r['i']))
	

print("------")
print("Broj resenja: " + str(i))
