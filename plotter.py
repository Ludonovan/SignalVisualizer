import matplotlib.pyplot as plt
import pandas as pd

filename = input("Which file do you want to plot? ")
filename = "outputs/" + filename

try:
	data = pd.read_csv(filename)

	x = data["time"]
	y = data["value"]

	plt.plot(x, y)

	plt.xlabel("Time")
	plt.ylabel("Amplitude")
	plt.title("Plot of " + filename)
	plt.grid(True)
	plt.show()

except KeyError as e:
	print(f"Column not found in file: {e}")
except FileNotFoundError:
	print(f"File not found: {filename}")
