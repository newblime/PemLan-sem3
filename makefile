main: compile link delete_compiled
	

link:
<<<<<<< HEAD
	g++ -o bensin *.o ./libOutput.dll
=======
	g++ -o bensin *.o ./User32.lib
>>>>>>> 1c6cc5e7d47d93ad8e16a03df289ed2ab10a95e5

compile:
	g++ -c *.cpp

delete_compiled:
	del *.o