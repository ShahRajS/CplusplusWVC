#include <iostream>
#include <iomanip>
#include <assert.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
/* Example output:
   triangle(cout, 3, 5) will print this to cout:
   ***
   ****
   *****
   *****
   ****
   ***
*/

void triangle(ostream& outs, unsigned int m, unsigned int n) {
    assert(m <= n);
    if (m == n) {
        cout << string(m, '*') << "\n";
        cout << string(m, '*') << "\n";
        return;
    }
    cout << string(m, '*') << "\n";
    triangle(outs, m + 1, n);
    cout << string(m, '*') << "\n";
    return;
}

void numbers(ostream& outs, const string& prefix, unsigned int levels) {
    if (levels == 0) {
        cout << prefix << "\n";
        return;
    }
    for (int i = 1; i < 10; ++i) {
        numbers(outs, ((prefix + (char('0' + i))) + '.'), levels - 1);
    }
    return;
}

// Postcondition: A true return value means that it is possible to win
   // the bear game by starting with n bears. A false return value means that
   // it is not possible to win the bear game by starting with n bears.
   // Examples:
   //   bear(250) is true (as shown above)
   //   bear(42) is true
   //   bear(84) is true
   //   bear(53) is false
   //   bear(41) is false

bool bears(int n) {
    if (n == 42) {
        return true;
    }
    if (n % 2 == 0) {
        if (bears(n / 2)) {
            return true;
        }
    }
    if (n % 3 == 0 or n % 4 == 0) {
        if (bears(n - ((n % 10) * ((n % 100) / 10)))) {
            return true;
        }
    }
    if (n % 5 == 0) {
        if (bears(n - 42)) {
            return true;
        }
    }
    return false;
}

int fibonacci_recursive(int n) {
    if (n == 0 or n == 1) {
        return 1;
    }
    else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int fib_iterative(int n) {
    if (n == 1 || n == 2)
        return 1;
    int A[2][2] = { { 1, 1 },{ 1, 0 } };
    int B[2][2] = { { 1, 1 },{ 1, 0 } };
    int temp[2][2];
    while (n >= 2) {
        for (int i = 0; i < 2; i++)
            for (int k = 0; k < 2; k++) {
                temp[i][k] = 0;
                for (int j = 0; j < 2; j++)
                    temp[i][k] += A[i][j] * B[j][k];
            }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                B[i][j] = temp[i][j];
        n--;
    }
    return B[0][1];
}

int main()
{
    triangle(cout, 3, 5);
    numbers(cout, "hello", 2);
    high_resolution_clock::time_point startTimeR;
    high_resolution_clock::time_point endTimeR;
    duration<float> time_span_r;
    high_resolution_clock::time_point startTimeI;
    high_resolution_clock::time_point endTimeI;
    duration<float> time_span_i;
    cout << bears(250) << "\n";

    cout << "Fibonacci\n";
    cout << fixed << setw(5) << "n" << setw(20) << "Recursive" << setw(20) <<
        "time_r(s)" << setw(20) << "Iterative" << setw(20) << "time_i(s)\n";

    for (int n = 1; n <= 45; ++n) {
        startTimeR = high_resolution_clock::now();
        int fib_r = fibonacci_recursive(n);
        endTimeR = high_resolution_clock::now();
        time_span_r = endTimeR - startTimeR;

        startTimeI = high_resolution_clock::now();
        int fib_i = fib_iterative(n);
        endTimeI = high_resolution_clock::now();
        time_span_i = endTimeI - startTimeI;

        cout << fixed << setw(5) << n << setw(20) << fib_r << setw(20) << 
            time_span_r.count() << setw(20) << fib_i << setw(20) << time_span_i.count() << "\n";
    }

    std::cout << fixed;
    std::cout << "The recursive function took " << time_span_r.count() << " seconds.\n";
    std::cout << "The iterative function took " << time_span_i.count() << " seconds.";
    std::cout << std::endl;
}

