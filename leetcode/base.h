#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>



using namespace std;

// template <class X>
// class Base {
//     private:
//         vector<X> v;
//         int nums;

//     public:
//         Base();
//         int count();
// };

template <class Temp>
class Calculator
{
private:
    Temp n1, n2;
    
public:
    Calculator(Temp num1, Temp num2): n1(num1), n2(num2){};
    void show() {
        cout << "Addition is: " << n1 << "+" << n2 << "=" << addition() << endl;
        cout << "Subtraction is: " <<n1 << "-" << n2 << "=" << subtraction() << endl;
        cout << "Product is: " << n1 << "*" << n2 << "=" << multiplication() << endl;
        cout << "Division is: " << n1 << "/" << n2 << "=" << division() << endl;
    }
    Temp addition() {
        return n1 + n2;
    }
    Temp subtraction() {
        return n1 - n2; 
    }
    Temp multiplication() {
        return n1 * n2;
    }
    Temp division() {
        return n1 / n2;
    }
};