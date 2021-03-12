import csv
import matplotlib.pyplot as plt

def get_p(rows, j):
    if j==0:
        return get_pi(rows, 0)


def get_ema(rows, j, ema):
    if j==0:
        return get_pi(rows, 0)
    return (7*ema+2*get_pi(rows, j))/9

def get_pi(rows, i):
    a = i
    b = a+7
    avg = []
    for j in range(i, i+8):
        avg.append(float(rows[i][4]))
        print(rows[i][4])
    avg = sum(avg)/len(avg)
    return avg

def read_data():
    rows = []
    with open("SBER_201210_210310 (1).csv", encoding='utf-8') as r_file:
        file_reader = csv.reader(r_file, delimiter = ";")
        count = 0
        for row in file_reader:
            rows.append(row)
            count += 1
    rows = rows[1:len(rows)]
    return rows


if __name__ == '__main__':
    rows = read_data()
    x = range(0, len(rows))
    y = []
    y1 = []
    for i in range(len(rows)):
        y.append(get_pi(rows, i))
    y1.append(get_pi(rows, 0))
    for i in range(1, len(rows)):
        y1.append(get_ema(rows, i, y1[i-1]))
    plt.plot(x, y)
    plt.plot(x, y1)
    print(y)
    print(y1)
    plt.show()


    