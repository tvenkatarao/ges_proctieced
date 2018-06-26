import fileinput
import os
import subprocess
f=open("file_python.txt","r")
r=f.read()

#fileinput.filelineno()

# Function definition is here
#sum = lambda arg1, arg2: arg1 + arg2;

# Now you can call sum as a function
#print "Value of total : ", sum( 10, 20 )
#print "Value of total : ", sum( 20, 20) 
#for i in (list(r.split())):
#	print i, r.count(i)#,r.filelineno(i)
num_lines = 0
for i in r:
	if i=="\n":
		num_lines += 1
#	if i=="filecmp":
#
#		print("Number of lines:")
print(num_lines)
#t= grep -i "filecmp" r
#print t
#print r.find("filecmp")
#if "\n" in r:

#b=f.readline()
#while b:
 #   cmd='grep -nir %e file_python.txt'%b    #my2 is the file in which we are looking for b
  #  os.system(cmd)
   # b=f.readline()
f.close()

a="file"
cmd='grep -nir %s file_python.txt'%a
os.system(cmd)
