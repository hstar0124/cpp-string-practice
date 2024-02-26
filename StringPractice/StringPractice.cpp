#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    String str1("TESTL");
    
    cout << str1.At(0) << endl;
    cout << str1.Size() << endl;
    cout << str1.Front() << endl;
    cout << str1.Back() << endl;

    String str2("Blow");
    str2.Print();
    str2.Resize(2);
    str2.Print();
    cout << str2.Size() << endl;
    str2.Resize(10, 'c');
    str2.Print();
    cout << str2.Size() << endl;

    String str3("BBCream IceCream");
    cout << str3.Capacity() << endl;
    str3.Reserve(20);
    cout << str3.Capacity() << endl;
    str3.ShrinkToFit();
    cout << str3.Capacity() << endl;
    str3.Clear();
    str3.Print();
    cout << str3.Emtpy() << endl;

    String str4 = str1.SubStr();
    str4.Print();

}

