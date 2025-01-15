# Signal Visualizer
## Uses C to create a .csv file containing data for a signal, then plots using matplotlib 

## How to run
### You first need:
- python3
- matplotlib
- pandas
- gcc
- make

### To run:
- run "make",
- run "./visualizer" and input parameters,
- then run "python3 plotter.py" and input the name of the csv file you want to plot
	- Only input the filename, not the whole path ("sine.csv" instead of "outputs/sine.csv")

### Inputs
- Desired Amplitude, Frequency, and/or Phase.
- Duration: How long the simulation should run.
- Sampling rate: Number of data points per unit time.

### Outputs
- visualizer.c: Outputs a .csv file containing data representing the signal
    - Can output,
        - Sine
        - Square
        - Triangular
        - Sawtooth
        - Step (WIP)
        - Impulse
        - Exponential Decay
        - Random
- plotter.py: Outputs a graphical window containing a plot of the signal.

### TODO
- Fix step function, currently returning square wave.

