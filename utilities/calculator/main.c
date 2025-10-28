#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

static void flush_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static bool read_double(const char *prompt, double *out) {
    printf("%s", prompt);
    if (scanf("%lf", out) != 1) {
        printf("Invalid number. Try again.\n");
        flush_input();
        return false;
    }
    return true;
}

static long long factorial(int n) {
    if (n < 0) return -1;        
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        if (res > LLONG_MAX / i) return -1; 
        res *= i;
    }
    return res;
}

static void menu(void) {
    puts("\n===== Calculator =====");
    puts("1) Add (a + b)");
    puts("2) Subtract (a - b)");
    puts("3) Multiply (a * b)");
    puts("4) Divide (a / b)");
    puts("5) Power (a ^ b)");
    puts("6) Square root (√a)");
    puts("7) Factorial (n!)");
    puts("8) Memory: Store");
    puts("9) Memory: Recall");
    puts("0) Exit");
    printf("Choose: ");
}

int main(void) {
    double a, b, mem = 0.0;
    int choice;

    puts("Welcome to the Console Calculator!");

    for (;;) {
        menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            flush_input();
            continue;
        }

        switch (choice) {
            case 1: 
                if (!read_double("a = ", &a) || !read_double("b = ", &b)) break;
                printf("Result: %.10g\n", a + b);
                break;
            case 2: 
                if (!read_double("a = ", &a) || !read_double("b = ", &b)) break;
                printf("Result: %.10g\n", a - b);
                break;
            case 3: 
                if (!read_double("a = ", &a) || !read_double("b = ", &b)) break;
                printf("Result: %.10g\n", a * b);
                break;
            case 4: 
                if (!read_double("a = ", &a) || !read_double("b = ", &b)) break;
                if (b == 0.0) {
                    puts("Error: division by zero.");
                } else {
                    printf("Result: %.10g\n", a / b);
                }
                break;
            case 5: 
                if (!read_double("base a = ", &a) || !read_double("exponent b = ", &b)) break;
                printf("Result: %.10g\n", pow(a, b));
                break;
            case 6: 
                if (!read_double("a = ", &a)) break;
                if (a < 0.0) puts("Error: sqrt of negative number.");
                else printf("Result: %.10g\n", sqrt(a));
                break;
            case 7: { 
                double nd;
                if (!read_double("n (integer, 0..20) = ", &nd)) break;
                int n = (int)nd;
                if (nd != (double)n || n < 0 || n > 20) { 
                    puts("Error: please enter an integer between 0 and 20.");
                    break;
                }
                long long f = factorial(n);
                if (f < 0) puts("Overflow or invalid n.");
                else printf("Result: %lld\n", f);
                break;
            }
            case 8: 
                if (!read_double("Value to store in M = ", &mem)) break;
                printf("Stored M = %.10g\n", mem);
                break;
            case 9: 
                printf("Memory M = %.10g\n", mem);
                break;
            case 0:
                puts("Bye!");
                return 0;
            default:
                puts("Unknown option. Try again.");
        }
    }
}
