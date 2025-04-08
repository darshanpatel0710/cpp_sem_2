/*A mathematical research group aimed to create a software model for handling and performing
operations on complex numbers efficiently. To achieve this, they designed a Complex class that
encapsulates the real and imaginary parts of a complex number. The class supports essential operator
overloading to enhance usability, including the addition and subtraction of complex numbers and
custom input and output functionality through the << and >> operators. These overloaded operators
ensure seamless arithmetic and user interaction with the system.
The task involves implementing this system and exploring its capabilities by performing various
operations on complex numbers. Participants are expected to overload the specified operators and
use them to add and subtract complex numbers, as well as to facilitate user-friendly input and output.
Additionally, the solution encourages experimenting with managing collections of complex numbers
to perform batch operations.*/

#include<iostream>
using namespace std;

class complex_number
{
    int real_part;
    int img_part;

public:
    void inputdata(int r, int i)
    {
        real_part = r;
        img_part = i;
    }


    complex_number operator+(complex_number &x)
    {
        complex_number t;
        t.real_part = real_part + x.real_part;
        t.img_part = img_part + x.img_part;
        return t;
    }
     complex_number operator-(complex_number &x)
    {
        complex_number t;
        t.real_part = real_part - x.real_part;
        t.img_part = img_part - x.img_part;
        return t;
    }

    void display()
    {
        cout << real_part;
        if (img_part >= 0)
           {
               cout << "+";
           }
        cout << img_part << "i" << endl;
    }
};

int main()
{
    int n;
    complex_number c1, c2, c3;

    c1.inputdata(4, 3);
    c2.inputdata(5, -6);

    cout<<"Enter 1 for add two complex number"<<endl;
    cout<<"Enter 2 for subtraction of two complex number"<<endl;
    cin>>n;
    switch(n)
    {
    case 1 : c3 = c1 + c2;

        break;
    case 2:  c3 = c1 - c2;

        break;
    }

    c3.display();

    cout<<"\n24CE076_Patel Darshan";

    return 0;
}

