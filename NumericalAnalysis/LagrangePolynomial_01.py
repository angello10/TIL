def LagrangePolynomial(points) :
    def polynomial(x) :
        y = 0
        for i in range(len(points)) :
            L = 1;
            for j in range(len(points)) :
                if i == j :
                    continue
                L *= (x - points[j][0]) / (points[i][0] - points[j][0])
            y += L * points[i][1]
        return y
    return polynomial