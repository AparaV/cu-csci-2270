/** Write a function called isPrime that takes an integer argument and identifies whether the argument is prime or not.
 ** The function does not have a return value. It should print "Yes" if the number is prime, "No" otherwise.
 ** Use the following function definition:
 **   void isPrime(int number);
 */

 void isPrime(int n){

   //A faster version would use sqrt(n) from <cmath> instead of n/2
    for(int i = 2; i < n / 2; ++i){
        if(n % i == 0){
            std::cout << "No" << std::endl;
            return;
        }
    }

    std::cout << "Yes" << std::endl;
    return;
}
