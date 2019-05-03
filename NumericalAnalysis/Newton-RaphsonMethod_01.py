def newton(f, d, start, iteration, step) :
	x = start
 
	for i in range(iteration) :
		x -= f(x) * d(x) * step
 
	return x
 
print(newton(lambda x: x * x - 2, lambda x: 2 * x, 1, 1000, 0.1))
	