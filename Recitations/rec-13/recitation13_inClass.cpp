#include <iostream>
#include <cmath>

using namespace std;

int ComputeFactorial(int number) {
	int fact = 0;
	
	for (int j = 1; j <= number; j++) {
		fact = fact * j;
	}
	
	return fact;
}

double ComputeSeriesValue(double x, int n) {
	double seriesValue = 0.0;
	double xpow = 1;

	for (int k = 0; k <= n; k++) {
		seriesValue += xpow / ComputeFactorial(k);
		xpow = xpow * x;
	}

	return seriesValue;
}

int main() {

	double seriesValue = ComputeSeriesValue(2, 3);
	cout << "The value of the series is " << seriesValue << endl;

	return 0;
}


