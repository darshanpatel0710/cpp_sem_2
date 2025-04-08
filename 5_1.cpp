/*A software development team aimed to design a versatile utility that could perform basic arithmetic

operations while demonstrating the concept of function overloading. This effort resulted in a class-
based calculator system capable of handling various combinations of input types, such as integers and

floating-point numbers. The system includes multiple overloaded add functions, each tailored to
accept distinct input types and perform addition operations accordingly. This approach ensures the
calculator is adaptable and provides consistent functionality regardless of the input types.
The case revolves around testing and validating the versatility of this calculator. Participants are
expected to create instances of the calculator, invoke the appropriate overloaded functions for various
input scenarios, and store the resulting values for further analysis. To organize and display these
results, the system incorporates methods to sequentially process and present the outcomes.*/

#include<iostream>
using namespace std;
class calculator
{
    int sum;
    double SUM;
public:
    int add(int number1 , int number2)
    {
        sum=number1+number2;
    }

    double add(double number1 , double number2)
    {
        SUM=number1+number2;
    }

    void display()
    {
        cout<<"Number1 + Number2 ="<<sum<<endl;
        cout<<"Number1 + Number2 ="<<SUM<<endl;
    }

};

int main()
{
    calculator cal;

    cal.add(20,30);
    cal.add(20.5,30.3);
    cal.display();

    cout<<"24CE076_Patel Darshan";
}
