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
    String str5 = str1.SubStr(2);
    str5.Print();
    String str6 = str1.SubStr(2, 1);
    str6.Print();

    String str10 = "BomBom";
    str10.Replace(3, 2, "TEST");
    str10.Print();

    String compare1 = "compare";
    String compare2 = "compare";
    String compare3 = "compare1";
    String compare4 = "appleea";

    cout << compare1.Compare(compare2) << endl;
    cout << compare1.Compare(compare3) << endl;
    cout << compare1.Compare(compare4) << endl;

    cout << endl;
    cout << compare1.Find(nullptr) << endl;
    cout << compare1.Find("o") << endl;
    cout << compare1.Find("o", 3) << endl;
    cout << compare4.Find("ea") << endl;


    String pushPop = "Test Push Pop Back";
    pushPop.PushBack('!');
    pushPop.Print();
    pushPop.PopBack();
    pushPop.Print();
    cout << endl;

    String iteratorTest = "Iterator Test";
    String::iterator it;
    for (it = iteratorTest.Begin(); it != iteratorTest.End(); it++)
    {
        cout << *it;
        if (*it == 'o')
            break;
    }

    if (it != iteratorTest.End())
    {
        cout << "찾음" << endl;
    }
    else
    {
        cout << "못 찾음" << endl;
    }
    cout << endl;


}

