visualizer: visualizer.o
	gcc -o visualizer visualizer.o -lm

visualizer.o: visualizer.c
	gcc -c visualizer.c visualizer.h 

clean:
	rm visualizer visualizer.o visualizer.h.*
	clear
