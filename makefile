main: compile link delete_compiled
	

link:
	g++ -o bensin *.o ./libOutput.dll

compile:
	g++ -c *.cpp

delete_compiled:
	del *.o