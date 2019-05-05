import matplotlib.pylab as plt
from math import exp

def EulerMethod(f, a, b, h, y) : 
    x_list = [a]
    y_list = [y]
    
    x = a
    
    for _ in range(int((b - a) / h)) :
        x += h
        y += h * f(x, y)
        
        x_list.append(x)
        y_list.append(y)
        
    return x_list, y_list


x, y = EulerMethod(lambda x, y: 2 * x * (y + 1), 0, 3, 0.01, 0)
plt.plot(x, y)

for i in range(len(x)) :
    y[i] = exp(x[i] ** 2) - 1
plt.plot(x, y)
plt.show()
