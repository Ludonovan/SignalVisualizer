# Signal Visualizer
## Uses C to create a .csv file containing data for a signal, then plots using matplotlib 

## How to run
### You first need:
- python3
- matplotlib
- pandas
- numpy
- gcc
- make

### To run:
- run "make"
- run "./visualizer" and input parameters
- "ls outputs" to see the newly created file
- then run "python3 plotter.py" and input the name of the csv file you want to plot
	- Only input the filename, not the whole path ("sine.csv" instead of "outputs/sine.csv")

### Outputs
- visualizer.c: Outputs a .csv file containing data representing the signal
    - Can output,
        - Sine
        - Square
        - Triangular
        - Sawtooth
        - Step
        - Impulse
        - Exponential Decay
        - Sinc
        - Rectangle 
        - Random
- plotter.py: Outputs a graphical window containing a plot of the signal.
    - Can also do FFT on signal.

### TODO (Possible additional features)
- Create additional inputs for waves:
    - Start/Stop/Run times
    - Vmax/Vmin
    - Phase in rads || deg
- Signal manipulation tools
    - Filters
        - low-pass, high-pass, etc.
    - Amplifiers
    - Time/Frequency domain manipulation
        - scaling, shifting, reversing, etc.
    - Modulation/Demodulation
    - Compression
