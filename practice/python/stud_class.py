
class student:
	def __init__(self,rollno, grade):
		self.rollno=rollno
		self.grade=grade
	def display(self):
		print "roll_no= ",self.rollno,"grade= ",self.grade,"age= ",self.age
stu1=student(45,"a")
stu1.age=17
stu1.display()
del stu1.age
stu1.display()

