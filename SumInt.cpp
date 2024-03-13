#include <stdlib.h>
#include <math.h>

int main() {
    int sum = 0;  // Initialize a variable to hold the sum

    // Loop from 1 to 100 and add each number to the sum
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }

    // Print the sum
    std::cout << "The sum of integers from 1 to 100 is: " << sum << std::endl;

    return 0;
}
