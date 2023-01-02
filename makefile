main: compile link delete_compiled
	

link:
	g++ -o bensin *.o ./User32.lib

compile:
	g++ -c *.cpp

delete_compiled:
	del *.o