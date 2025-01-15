visualizer: visualizer.o
	gcc -o visualizer visualizer.o -lm

visualizer.o: visualizer.c
	gcc -c visualizer.c 

clean:
	rm visualizer visualizer.o
	clear
