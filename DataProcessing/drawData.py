import matplotlib.pyplot as plt

with open("DataProcessing/InterceptedData/data.txt", "r") as file:
    lines = file.readlines()

data = []
for line in lines:
    data.append(float(line.strip()))

plt.plot(data)
plt.xlabel("Samples")
plt.ylabel("Data")
plt.title("Data from Arduino")
plt.grid(True)
plt.show()
