#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Screen functions
int PrintInstructions();

// Math functions
void add(double dbl1, double dbl2);
void substract(double dbl1, double dbl2);
void multiply(double dbl1, double dbl2);
void divide(double dbl1, double dbl2);
void power(double base, int exponent);
void exponential(const double e, int exponent);
void factorial(int num);
void random(int int1, int int2);
void sumRange(int int1, int int2);
void roundDouble(double dbl1);
void roundUp(double dbl1);
void roundDown(double dbl1);
void min(double dbl1, double dbl2);
void max(double dbl1, double dbl2);

int main() 
{
    
    const double e = 2.71828;
    srand(time(NULL));
    
    char Operator;
    int int1, int2, exponent, returnVal;
    double dbl1, dbl2, base;
    
    // Variable returnVal only exists to fulfill all requirements (atleast one function must return a value)
    returnVal = PrintInstructions();
    
    while(Operator != 'q'){
        printf("Please enter your equation:\n");
        scanf(" %c", &Operator);
        if(Operator != 'q'){
            switch(Operator){
                case '+':
                    scanf(" %lf %lf", &dbl1, &dbl2);
                    add(dbl1, dbl2);
                    break;
                case '-':
                    scanf(" %lf %lf", &dbl1, &dbl2);
                    substract(dbl1, dbl2);
                    break;
                case '*':
                    scanf(" %lf %lf", &dbl1, &dbl2);
                    multiply(dbl1, dbl2);
                    break;
                case '/':
                    scanf(" %lf %lf", &dbl1, &dbl2);
                    divide(dbl1, dbl2);
                    break;
                case '^':
                    scanf(" %lf %d", &base, &exponent);
                    power(base, exponent);
                    break;
                case 'e':
                    scanf(" %d", &exponent);
                    exponential(e, exponent);
                    break;
                case '!':
                    scanf(" %d", &int1);
                    factorial(int1);
                    break;
                case 'r':
                    scanf(" %d %d", &int1, &int2);
                    random(int1, int2);
                    break;
                case 's':
                    scanf(" %d %d", &int1, &int2);
                    sumRange(int1, int2);
                    break;
                case '~':
                    scanf(" %lf", &dbl1);
                    roundDouble(dbl1);
                    break;
                case '\'':
                    scanf(" %lf", &dbl1);
                    roundUp(dbl1);
                    break;
                case '_':
                    scanf(" %lf", &dbl1);
                    roundDown(dbl1);
                    break;
                case '<':
                    scanf(" %lf %lf", &dbl1, &dbl2);
                    min(dbl1, dbl2);
                    break;
                case '>':
                    scanf(" %lf %lf", &dbl1, &dbl2);
                    max(dbl1, dbl2);
                    break;
                default:
                    printf("Please enter a valid operand, refer to instructions below:\n\n");
                    PrintInstructions();
                    break;
            }
        }
    }
    
    return returnVal;
    
}

int PrintInstructions()
{
    printf("\nWelcome to Peter Bou Saada's calculator\n\nSyntax: [Operator] [First Number] [Second Number] (without [])\n\n  +  Add two doubles\n  -  Substract two doubles\n  *  Multiply two doubles\n  /  Divide two doubles\n  ^  One double one integer, calculate the double raised to the integer\n  e  raise the constant e to the power of the integer\n  !  Calculate the factorial of the integer provided\n  r  Generate a random integer between the two integers (inclusive)\n  s  Calculate the sum of consecutive integers between two given integers (inclusive)\n  ~  Round given a double to the nearest integer\n  '  Round up given a double\n  _  Round down given a double\n  <  Determine the lesser of two doubles\n  >  Determine the greater of two doubles\n\n  q  Exit program\n\n");

    return 0;
}


// Math functions
void add(double dbl1, double dbl2) 
{
    double result = dbl1 + dbl2;
    printf("Result for your equation: %lf\n", result);
}
void substract(double dbl1, double dbl2) 
{
    double result = dbl1 - dbl2;
    printf("Result for your equation: %lf\n", result);
}
void multiply(double dbl1, double dbl2) 
{
    double result = dbl1 * dbl2;
    printf("Result for your equation: %lf\n", result);
}
void divide(double dbl1, double dbl2) 
{
    double result = dbl1 / dbl2;
    printf("Result for your equation: %lf\n", result);
}
void power(double base, int exponent) 
{
    double result = base;
    for(int i = 1; i < exponent; i++) 
    {
        result = result * base;
    }
    printf("Result for your equation: %lf\n", result);
}
void exponential(const double e, int exponent)
{
    power(e, exponent);
}
void factorial(int num) 
{
    int result = 1;
    for(int i = num; i > 0; i--)
    {
        result = result * i;
    }
    printf("Result for your equation: %d\n", result);
}
void random(int int1, int int2) 
{
    if(int1 < int2) 
    {
        int result = (int) rand() % int2 + int1;
        printf("Your random number is: %d\n", result);
    }
    else 
    {
        printf("Please make sure the first number is lower than the second number and that numbers are not identical\n");
    }
}
void sumRange(int int1, int int2) 
{
    int result = 0;
    if(int1 < int2)
    {
        for(int i = int1; i <= int2; i++){
            result += i;
        }
        printf("The sum of the numbers between range %d and %d is: %d\n", int1, int2, result);
    }
    else 
    {
        printf("Please make sure the first number is lower than the second number and that numbers are not identical\n");
    }
}
void roundDouble(double dbl1) 
{
    int result = 0;
    
    //if true round up
    if( (dbl1 + 0.5) >= ( (int) dbl1 + 1))
    {
        result = (int) dbl1 + 1;    
    }
    else
    {
        result = (int) dbl1;  
    }
    printf("Result for your equation: %d\n", result);
}
void roundUp(double dbl1) 
{
    int result = (int) dbl1 + 1;
    printf("Result for your equation: %d\n", result);
}
void roundDown(double dbl1) 
{
    int result = (int) dbl1;
    printf("Result for your equation: %d\n", result);
}
void min(double dbl1, double dbl2) 
{
    double result = 0;
    if(dbl1 > dbl2) 
    {
        result = dbl2;
        printf("Result for your equation: %lf\n", result);
    }
    else if(dbl1 < dbl2)
    {
        result = dbl1;
        printf("Result for your equation: %lf\n", result);
    }
    else
    {
        printf("Doubles cannot be identical.\n");
    }
}
void max(double dbl1, double dbl2) 
{
    double result = 0;
    if(dbl1 > dbl2) 
    {
        result = dbl1;
        printf("Result for your equation: %lf\n", result);
    }
    else if(dbl1 < dbl2)
    {
        result = dbl2;
        printf("Result for your equation: %lf\n", result);
    }
    else
    {
        printf("Doubles cannot be identical.\n");
    }
}