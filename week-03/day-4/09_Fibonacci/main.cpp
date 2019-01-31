
#include <iostream>

// The fibonacci sequence is a famous bit of mathematics, and it happens to
// have a recursive definition. The first two values in the sequence are
// 0 and 1 (essentially 2 base cases). Each subsequent value is the sum of the
// previous two values, so the whole sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21
// and so on. Define a recursive fibonacci(n) method that returns the nth
// fibonacci number, with n=0 representing the start of the sequence.

int fibonacciGenerator2000(int Element) {
    if (Element > 1) {
        return fibonacciGenerator2000(Element - 2) + fibonacciGenerator2000(Element - 1);
    } else {
        return Element;
    }
}

int main() {

    int element;
    std::cout << "The me which number element of the Fibonacci sequence would you like to get: " << std::endl;
    std::cin >> element;

    std::cout << "Your element is: " << fibonacciGenerator2000(element) << " Sweet." << std::endl;

    return 0;
}