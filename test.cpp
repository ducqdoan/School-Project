#include "myString.hpp"

int main(){
    
   string input;
   cout << "Enter string: " << endl;
   cin >> input;

   myString base(input);
   cout << "Test #1: ";    
    base.printStringScreen();
   string num;
   cout << endl;
   cout << "Enter a number:" << endl;
   cin >> num;
   myString number(num);
    cout << "Test #2: "; 
    number.printStringScreen();
    cout << endl;

    cout << "Test #3:";
    base.addStart(number);
    base.printStringScreen();
    cout << endl;

    cout << "Test #4:";
    base.setString("Record #");
    base.printStringScreen();
    cout << endl;
    cout << "Test #5:";
    base.addEnd(number);
    base.printStringScreen();
    cout << endl;

    cout << "Test #6: ";
    myString one(base.partString(7, 4).getString());
    one.printStringScreen();
    cout << endl;

    try{
    myString two(base.partString(-2,0).getString());
    }
    catch (invalid_argument& x){
        cout << "Test #7: ";
        cout << "Exception caught" << endl;
        cout << endl;
    }

    cout << "Test #8: ";
    one.replacePartString(number, 0);
    one.printStringScreen();
    cout << endl;

    cout << "Test #9: ";
    base.replaceWholeString(number);
    base.printStringScreen();
    cout << endl;

    cout << "Test #10: ";
    cout << base.compareString(number) << endl;
    cout << endl;

    cout << "Test #11: ";
    cout  << one.compareString(number) << endl;
    cout << endl;

    cout << "Test #12: ";
    cout << number.numericString() << endl;
    cout << endl;

    cout << "Test #13: ";
    cout << base.alphabeticString() << endl;
    cout << endl;
   

    
}