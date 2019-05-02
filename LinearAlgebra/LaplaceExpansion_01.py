def laplaceExpansion(M) :
	det = 0
	N = len(M)
	if (N == 1) :
		return M[0][0]
	
	for i in range(N) :
		m = []
		for x in range(N - 1) :
			m.append(M[x if x < i else x + 1][1:])
		det += M[i][0] * laplaceExpansion(m) * (1 if i % 2 == 0 else -1)
	return det