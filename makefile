main: compile link delete_compiled
	

link:
	g++ -o bensin *.o

compile:
	g++ -c *.cpp

delete_compiled:
	del *.o