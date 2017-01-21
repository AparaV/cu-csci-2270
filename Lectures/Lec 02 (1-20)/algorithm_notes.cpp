/*ALGORITHMS AND COMPLEXITY*/

/*

Algorithm

	Define pre and post conditions
	Correctness – need to produce correct results
	Cost – memory use and runtime
	Runtime – too many variables to calculate actual runtime (OS, language, etc.)
		Count code lines = theoretical runtime – each line = 1, actual runtime proportional to theoretical
	
	Pre conditions – condition for the algorithm to be defined ex : factorial(n); n > 0
	Post conditions – expected changes to return value after execution

*/
	
	
/*

Example :

	findItem(A, v) {
		//Pre : A is an array; v is of same type as elements in A
		//Post : Return last index where v is found in A
		index = -1;				//evaluated 1 time
		for x = 0 to A.end		//evaluated 5 times (4 + checking whether loop conditions are met)
			if A[x] == v		//evaluated 4 times
				index = x		//evaluated 2 times
		return index			//evaluated 1 time
	}

	Cost for A = [45, 34, 32, 34];
		findItem(A, 34) = 13
	Larger array A = [45, 34, ..., 34] (100 elements);
		findItem(A, 34) = 205
	Algorithm cost scales linearly with the size of A

*/

/*

Growth rate: How does algorithm scale with input size?

Big-Oh notation:
	Upper bound on growth as n -> infinity (n is size of input)
	i.e., worst case for all possible data

	n = size of input
	T(n) = algorithm's precise runtime
	f(n) = growth function

	growth rate of T(n) expressed by relation it to a growth function

	if T(n) grows faster than f(n)
		T(n) is in order of O(f(n))
	else
		T(n) is in order of O(n)

	T(n) is in O(n) iff T(n) <= C * f(n) where n is big for some large constant C

	Algorithm has 10000 startup cost (constant operations)
	T(n) = 10000 + 10 * n
	When C = 20, T(n) > C * f(n) for small n
	As n grows, T(n) <= C * f(n)
	constant operations matter less as n grows because we choose a different c
	coefficient of size also doesn't matter

*/

/*

Algorthmic Complexity

	Theoretical upper bound on growth rate of an algorithm

	1. If T(n) includes multiple terms, keep largest term (highest order) only
	2. Omit any coefficients
	
	findItem(A, v)

	T(n) = 3n + 3
	Therefore, T(n) is in O(n)


*/