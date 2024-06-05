#include <iostream>
#include<iomanip>
using namespace std;
struct Result
{
    int sum;
    int Subtraction;
    int Multiplication;
    float Division;
};
Result performOperation(int a, int b)
{
    Result num_result;
    num_result.sum = a + b;
    num_result.Subtraction = a - b;
    num_result.Multiplication = a * b;
    num_result.Division = static_cast<float>(a) / b; 
    return num_result;
}
int main()
{
    int num1, num2;
    cout << "Enter number 1 : ";
    cin >> num1;
    cout << "Enter number 2 : ";
    cin >> num2;

    Result num_result = performOperation(num1, num2);
    cout << "=============================================================================\n"
         << "Summation is : " << num1 << " + " << num2 << " = " << num_result.sum
         << "\nSubtraction is : " << num1 << " - " << num2 << " = " << num_result.Subtraction
         << "\nMultiplition is : " << num1 << " * " << num2 << " = " << num_result.Multiplication
         << "\nDivision is : " << fixed << setprecision(3) << num1 << " / " << num2 << " = " << num_result.Division 
         <<"\nExit!! \n=============================================================================\n";

    return 0;

}