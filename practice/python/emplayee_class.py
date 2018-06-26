# For mployee details 
class Employee:
	'common base class for all employees'
	empcount=0

	def __init__(self, name, salary):
		self.name = name
		self.salary = salary
		Employee.empcount +=1
	def displaycount(self): 
		print "Total Employee %d" % Employee.empcount

	def displayemployee(self):
		print "Name : ", self.name, ", Salary: ", self.salary

emp1 = Employee("sai", 3000)
emp2 = Employee('manti', 600)
emp1.displayemployee()
emp2.displayemployee()
print "Total Employee %d" % Employee.empcount
emp1.age = 8
emp1.age = 9
print "employee age:",emp1.age
print hasattr(emp1, 'age')
print hasattr(emp2, 'age')
print "deleting emp1.age"
del emp1.age
print "employee age:",emp1.age
print setattr(emp2,'age', 11 )
print getattr(emp2, 'age')
print hasattr(emp1, 'age')
print hasattr(emp2, 'age')

print "deleting emp1.age"
print delattr(emp2, 'age')
print hasattr(emp1, 'age')
print hasattr(emp2, 'age')

#print "Employee.__doc__:", Employee.__doc__
#print "Employee.__name__:", Employee.__name__
#print "Employee.__module__:", Employee.__module__
#print "Employee.__bases__:", Employee.__bases__
#print "Employee.__dict__:", Employee.__dict__
