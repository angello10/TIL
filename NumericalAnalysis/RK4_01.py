import matplotlib.pylab as plt
from math import exp

def RungeKuttaMethod(f, a, b, h, y) : 
    x_list = [a]
    y_list = [y]
    
    x = a
    
    for _ in range(int((b - a) / h)) :
        k_1 = h * f(x, y)
        k_2 = h * f(x + h / 2, y + k_1 / 2)
        k_3 = h * f(x + h / 2, y + k_2 / 2)
        k_4 = h * f(x + h, y + k_3)
        
        x += h
        y += (k_1 + k_2 * 2 + k_3 * 2 + k_4) / 6
        
        x_list.append(x)
        y_list.append(y)
        
    return x_list, y_list


x, y = RungeKuttaMethod(lambda x, y: 2 * x * (y + 1), 0, 2, 0.01, 0)
plt.plot(x, y)

for i in range(len(x)) :
    y[i] = exp(x[i] ** 2) - 1
plt.plot(x, y)
plt.show()
