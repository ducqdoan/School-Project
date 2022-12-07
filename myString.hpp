#include <iostream>
#include <fstream>

using namespace std;

class myString
{
private:
    char *ptr;
    int size0;
    fstream oneFile;
    ofstream outputFile;
    int count;

public:
    myString(string str);
    myString(myString &original);
    myString &operator=(myString &oldObj);
    int size();
    void addStart(myString myStr);
    void addEnd(myString myStr);
    myString partString(int startPos, int length);
    void replacePartString(myString myStr, int startPos);
    void replaceWholeString(myString myStr);
    int compareString(myString myStr);
    void initString();
    void setString(string str);
    string getString();
    void printStringScreen();
    bool numericString();
    bool alphabeticString();
    ~myString();
};

myString::myString(string str)
{

    oneFile.open("log.txt", ios::app);
    outputFile.open("output.txt", ios::app);
    count = 0;
    size0 = str.length();
    ptr = new char[size0];
    oneFile << count << endl;
    oneFile << "Method: Constructor" << endl;
    oneFile << setw(7) << right << "Parameter: string " << str << endl;
    oneFile << setw(7) << right << "Pointer:  ";
    for (int i = 0; i < size0; i++)
    {
        ptr[i] = str[i];
        oneFile << ptr[i];
    }
    oneFile << endl;
    oneFile << "Size: " << size0 << endl;
    count++;
    
}
myString::myString(myString &original)
{
    
    oneFile << count << endl;
    oneFile << "Method: Copy Constructor" << endl;
    oneFile << "Parameter: myString " << original.getString() << " " << original.size() << endl;
    size0 = original.size0;
    ptr = new char[size0];
    oneFile << "Pointer: ";
    for (int i = 0; i < size0; i++)
    {
        ptr[i] = original.ptr[i];
        oneFile << ptr[i];
    }
    oneFile << endl;
    oneFile << "Size: " << size0 << endl;
    count++;
    
}
myString &myString::operator=(myString &oldObj)
{
    
    oneFile << count << endl;
    oneFile << "Method: Overloaded assignment operator" << endl;
    oneFile << "Parameter: myString " << oldObj.getString() << " " << oldObj.size() << endl;
    size0 = oldObj.size0;
    delete[] ptr;
    ptr = new char[size0];
    oneFile << "Pointer:";
    for (int i = 0; i < size0; i++)
    {
        ptr[i] = oldObj.ptr[i];
        oneFile << ptr[i];
    }
    oneFile << endl;
    oneFile << "Size: " << size0 << endl;
    count++;
    
    return *this;
}
int myString::size()
{
    
    return size0;
}
void myString::addStart(myString str)
{
    
    oneFile << count << endl;
    oneFile << "Method: addStart" << endl;
    oneFile << "Parameter: myString" << str.getString() << " " << str.size() << endl;
    int strSize = str.size();
    int newSize = strSize + size0;
    char *temp = new char[newSize];
    for (int i = 0; i < strSize; i++)
    {
        temp[i] = str.getString()[i];
    }
    for (int i = 0; i < size0; i++)
    {
        temp[strSize + i] = ptr[i];
    }
    ptr = new char[newSize];
    ptr = temp;
    size0 = newSize;
    oneFile << "Pointer:";
    for (int i = 0; i < size0; i++)
    {
        oneFile << ptr[i];
    }
    oneFile << endl;
    oneFile << "Size: " << size0 << endl;
    count++;
    
}
void myString::addEnd(myString str)
{
   
    oneFile << count << endl;
    oneFile << "Method: addEnd" << endl;
    oneFile << "Parameter: myString " << str.getString() << " " << str.size() << endl;
    int strSize = str.size();
    int newSize = strSize + size0;
    char *temp = new char[newSize];
    for (int i = 0; i < size0; i++)
    {
        temp[i] = ptr[i];
    }
    for (int i = 0; i < strSize; i++)
    {
        temp[size0 + i] = str.getString()[i];
    }
    ptr = new char[newSize];
    ptr = temp;
    size0 = newSize;
    oneFile << "Pointer: ";
    for (int i = 0; i < size0; i++)
    {
        oneFile << ptr[i];
    }
    oneFile << endl;
    oneFile << "Size: " << size0 << endl;
    count++;
    
}

myString myString::partString(int startPos, int length)
{
    
    oneFile << count << endl;
    oneFile << "Method: partString" << endl;
    oneFile << "Parameter: int " << startPos << " int " << length << endl;
    if (startPos<0 | startPos> size0)
    {
        count++;
        oneFile << "Error: invalid start position." << endl;
        oneFile.close();
        throw invalid_argument("Start position must be within 0 - " + to_string(size0));
    }
    else if (length<0 | startPos + length> size0)
    {
        count++;
        oneFile << "Error: Out of range." << endl;
        oneFile.close();
        throw invalid_argument("Out of range");
    }
    else
    {
        string temp = "";
        for (int i = 0; i < length; i++)
        {
            temp = temp + ptr[startPos + i];
        }
        myString myStr(temp);
        oneFile << "Pointer: ";
        for (int i = 0; i < size0; i++)
        {
            oneFile << ptr[i];
        }
        oneFile << endl;
        oneFile << "Size: " << size0 << endl;
        count++;
        
        return myStr;
    }
}

void myString::replacePartString(myString myStr, int startPos)
{
    
    oneFile << count << endl;
    oneFile << "Method: replacePartString" << endl;
    oneFile << "Parameter: myString " << myStr.getString() << " " << myStr.size()
            << " int " << startPos << endl;
    if (startPos<0 | startPos> size0)
    {
        count++;
        oneFile << "Error: Invalid start position." << endl;
        throw invalid_argument("Start position must be within 0 - " + to_string(size0));
    }
    else
    {
        int i = 0;
        while (i < myStr.size() && i + startPos < size0)
        {
            ptr[startPos + i] = myStr.getString()[i];
            i++;
        }
        oneFile << "Pointer: ";
        for (int i = 0; i < size0; i++){
            oneFile << ptr[i];
        }
        oneFile << endl;
        oneFile << "Size: " << size0 << endl;
        count++;
        
    }
}

void myString::replaceWholeString(myString myStr)
{
    
    
    oneFile << count << endl;
    oneFile << "Method: replaceWholString" << endl;
    oneFile << "Parameter: myString " << myStr.getString() << myStr.size() << endl;  
    oneFile << "Pointer:";
    size0 = myStr.size();
    delete[] ptr;
    ptr = new char[size0];
    for (int i = 0; i < size0; i++)
    {
        ptr[i] = myStr.getString()[i];
        oneFile << ptr[i];
    }
    oneFile << endl;
    oneFile << "Size: " << size0 << endl;
    count++;
    
}

int myString::compareString(myString myStr)
{
    
    oneFile << count << endl;
    oneFile << "Method: compareString" << endl;
    oneFile << "Parameter: myString " << myStr.getString() << " " << myStr.size() << endl;
    int i = 0;
    count++;
    while (i < size0 | i < myStr.size())
    {
        if (ptr[i] < myStr.getString()[i])
        {
            
            return i;
        }
        if (ptr[i] > myStr.getString()[i])
        {
            
            return i * (-1);
        }
        i++;
    }
    
    return 0;
}

void myString::initString()
{
    
    oneFile << count << endl;
    oneFile << "Method: initString" << endl;
    oneFile << "Parameter: none" << endl;
    ptr = nullptr;
    size0 = 0;
    oneFile << "Pointer: ";
    for (int i = 0; i < size0; i++){
        oneFile << ptr[i];
    }
    oneFile << endl;
    oneFile << "Size: " << size0 << endl;
    count++;
    
}

void myString::setString(string str)
{
    
    oneFile << count << endl;
    oneFile << "Method: setString" << endl;
    oneFile << "Parameter: string " << str << endl;
    delete ptr;
    ptr = nullptr;
    size0 = str.length();
    ptr = new char[size0];
    oneFile << "Pointer: ";
    for (int i = 0; i < size0; i++)
    {
        ptr[i] = str[i];
        oneFile << ptr[i];
    }
    oneFile << endl;
    oneFile << "Size: " << size0 << endl;
    count++;
    
}

string myString::getString()
{
    string str = "";
    for (int i = 0; i < size0; i++)
    {
        str = str + ptr[i];
    }
    return str;
}

void myString::printStringScreen()
{
    
    for (int i = 0; i < size0; i++)
    {
        cout << ptr[i];
        outputFile << ptr[i];
    }
    cout << endl;
    outputFile << endl;
}

bool myString::numericString()
{
    for (int i = 0; i < size0; i++)
    {
        if (ptr[i] != 33 && ptr[i] != 37 && (ptr[i]<40 | ptr[i]> 57))
        {
            return false;
        }
    }
    return true;
}

bool myString::alphabeticString()
{
    for (int i = 0; i < size0; i++)
    {
        if ((ptr[i] >= 65 && ptr[i] <= 90) | (ptr[i] >= 97 && ptr[i] <= 122))
        {
            return true;
        }
    }
    return false;
}

myString::~myString()
{
    delete[] ptr;
    ptr = nullptr;
    oneFile.close();
    outputFile.close();
}
