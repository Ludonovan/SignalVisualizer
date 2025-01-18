import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

filename = input("Which file do you want to plot? ")
filename = "outputs/" + filename

ft = input("Fouier Transform? (Y/N): ") 

try:
    data = pd.read_csv(filename)
    
    x = data["time"]
    y = data["value"]

    if (ft.upper() == 'N'):

        plt.plot(x, y)
        plt.xlabel("Time")
        plt.ylabel("Amplitude")
        plt.title("Plot of " + filename)
    
    elif (ft.upper() == 'Y'):
        FFT = np.fft.fft(x)
        freqs = np.fft.fftfreq(len(x), y[1] - y[0])

        plt.plot(freqs, np.abs(FFT))

        plt.xlabel("Frequency")
        plt.ylabel("Magnitude")
        plt.title("Plot of FFT of " + filename)

    else:
        pass

    plt.grid(True)
    plt.show()

except KeyError as e:
    print(f"Column not found in file: {e}")
except FileNotFoundError:
    print(f"File not found: {filename}")
