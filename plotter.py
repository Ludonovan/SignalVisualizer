import matplotlib.pyplot as plt
import pandas as pd

file = input("Which file do you want to plot? ")

try:
	data = pd.read_csv(file)

	x = data["time"]
	y = data["value"]

	plt.plot(x, y)

	plt.xlabel("Time")
	plt.ylabel("Amplitude")
	plt.title("Plot of " + file)
	plt.grid(True)
	plt.show()

except KeyError as e:
	print(f"Column not found in file: {e}")
except FileNotFoundError:
	print(f"File not found: {filename}")
