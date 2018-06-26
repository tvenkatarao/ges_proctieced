x=5
def f1():
	global x;
	x=10
def f2(a, b):
#	global x;
 	return a+b+x
f1()
total=f2(1,2)
print(total)
