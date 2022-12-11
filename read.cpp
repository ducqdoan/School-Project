#include "header.hpp"

int main()
{
    ifstream file("integer.dat");
    ofstream errorFile("errorlog.txt");
    if (!(file))
    {
        cout << "File does not exist." << endl;
        file.close();
    }
    else if (file.seekg(0, ios::end).tellg() == 0)
    {
        cout << "File is empty." << endl;
        file.close();
    }
    else
    {
        cout << "**Welcome to the program.**" << endl;
        cout << endl;
        
        int num;
        

        Node *head = nullptr;
        Node *ptr = nullptr;
        Node *lastPtr = nullptr;
        Node *last = nullptr;

        Node *ptrOdd = nullptr;
        Node *lastPtrOdd = nullptr;
        Node *headOdd = nullptr;
        Node *lastOdd = nullptr;

        Node *ptrEven = nullptr;
        Node *lastPtrEven = nullptr;

        Node *headEven = nullptr;
        Node *lastEven = nullptr;

        int length = 9;
        cout << "Current length: " << length << endl;
        int size = sizeof(int);
        file.seekg(0, ios::beg);
        file.read(reinterpret_cast<char *>(&num), size);
        head = new Node;
        head->data = num;
        head->next = new Node;
        head->prev = nullptr;
        head->nextOddEven = new Node;
        head->prevOddEven = nullptr;
        last = head;
        ptr = head;

        bool odd = false;
        bool even = false;
        if (num % 2 == 0)
        {
            headEven = head;
            lastEven = headEven;
            ptrEven = headEven;
            even = true;
        }
        if (num % 2 != 0)
        {
            headOdd = head;
            lastOdd = headOdd;
            ptrOdd = headOdd;
            odd = true;
        }
        int count = 1;

        while (count < length)
        {
            file.seekg(count * size, ios::beg);
            file.read(reinterpret_cast<char *>(&num), size);
            if (num < 1){
                errorFile << "Error reading at position" << file.tellg() << " : Integer " 
                << num << " is lower than 1.";
            }
            lastPtr = ptr;
            ptr->next = new Node;
            ptr = ptr->next;
            ptr->data = num;
            ptr->prev = lastPtr;
            last = ptr;
            if (num % 2 == 0)
            {
                if (even == false)
                {
                    headEven = ptr;
                    lastEven = headEven;
                    ptrEven = ptr;
                    even = true;
                }
                else
                {
                    lastPtrEven = ptrEven;
                    ptr->prevOddEven = lastPtrEven;
                    ptrEven->nextOddEven = ptr;
                    ptrEven = ptrEven->nextOddEven;
                    lastEven = ptrEven;
                }
            }
            if (num % 2 != 0)
            {
                if (odd == false)
                {
                    headOdd = ptr;
                    lastOdd = headOdd;
                    ptrOdd = ptr;
                    odd = true;
                }
                else
                {
                    lastPtrOdd = ptrOdd;
                    ptr->prevOddEven = lastPtrOdd;
                    ptrOdd->nextOddEven = ptr;
                    ptrOdd = ptrOdd->nextOddEven;
                    lastOdd = ptrOdd;
                }
            }
            count++;
        }
        last->next = nullptr;
        head->prev = nullptr;
        headEven->prevOddEven = headOdd->prevOddEven = nullptr;
        lastEven->nextOddEven = lastOdd->nextOddEven = nullptr;
        bool sort = false;
        ptr = head->next;
        lastPtr = head;
//Bubble sort list
        while (!sort)
        {
            sort = true;
            ptr = head->next;
            lastPtr = head;
            for (int i = 1; i < length; i++)
            {
                if (ptr->data < lastPtr->data)
                {
                    sort = false;
                    num = ptr->data;
                    ptr->data = lastPtr->data;
                    lastPtr->data = num;
                    ptr = ptr->next;
                    lastPtr = lastPtr->next;
                }
            }
        }

        int choice = 0;
        while (choice != 6)
        {
            char ad;
            cout << "Choose action:" << endl;

            cout << "1. Print full list" << endl;
            cout << "2. Print even list" << endl;
            cout << "3. Print odd list" << endl;
            cout << "4. Add" << endl;
            cout << "5. Delete" << endl;
            cout << "6. Exit" << endl;
            while (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please try again: " << endl;
            }
            switch (choice)
            {
// Choice 1: print full list
            case 1:
            {
                cout << "Ascending (A) or Descending (D):" << endl;
                while (!(cin >> ad))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Try again." << endl;
                }
                ad = tolower(ad);
                switch (ad)
                {
    // Ascending
                case 'a':
                    cout << "Ascending:" << endl;
                    ptr = head;

                    while (ptr->data != last->data)
                    {
                        cout << ptr->data << endl;
                        ptr = ptr->next;
                    }
                    cout << last->data << endl;
                    break;
    // Descending
                case 'd':
                    cout << "Descending:" << endl;
                    ptr = last;

                    while (ptr->data != head->data)
                    {
                        cout << ptr->data << endl;
                        ptr = ptr->prev;
                    }
                    cout << head->data << endl;
                    break;
                default:
                    cout << "Option not available." << endl;
                    break;
                }
                break;
            }

 // Print even list
            case 2:
            {
                cout << "Ascending (A) or Descending (D):" << endl;
                while (!(cin >> ad))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Try again." << endl;
                }
                ad = tolower(ad);
                switch (ad)
                {
    // Ascending
                case 'a':
                    cout << "Ascending:" << endl;
                    ptrEven = headEven;

                    while (ptrEven->nextOddEven != nullptr)
                    {
                        cout << ptrEven->data << endl;
                        ptrEven = ptrEven->nextOddEven;
                    }
                    cout << lastEven->data << endl;
                    break;
    // Descending
                case 'd':
                    cout << "Descending:" << endl;
                    ptrEven = lastEven;

                    while (ptrEven->data != headEven->data)
                    {
                        cout << ptrEven->data << endl;
                        ptrEven = ptrEven->prevOddEven;
                    }
                    cout << headEven->data << endl;
                    break;
                default:
                    cout << "Option not available." << endl;
                    break;
                }
                break;
            }
// Print odd list:
            case 3:
            {
                cout << "Ascending (A) or Descending (D):" << endl;
               while (!(cin >> ad))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Try again." << endl;
                }
                ad = tolower(ad);
                switch (ad)
                {
    // Ascending
                case 'a':
                    cout << "Ascending:" << endl;
                    ptrOdd = headOdd;
                    while (ptrOdd->nextOddEven != nullptr)
                    {
                        cout << ptrOdd->data << endl;
                        ptrOdd = ptrOdd->nextOddEven;
                    }
                    cout << lastOdd->data << endl;
                    break;
    // Descending
                case 'd':
                    cout << "Descending:" << endl;
                    ptrOdd = lastOdd;
                    while (ptrOdd->prevOddEven != nullptr)
                    {
                        cout << ptrOdd->data << endl;
                        ptrOdd = ptrOdd->prevOddEven;
                    }
                    cout << headOdd->data << endl;
                    break;
                default:
                    cout << "Option not available." << endl;
                    break;
                }
                break;
            }
//Add items:
            case 4:
            {
                cout << "Enter an integer to add:" << endl;
                while (!(cin >> num))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please enter a valid integer" << endl;
                }
                if (num < 1){
                    errorFile << "Error: inputted integer " << num <<  " is lower than 1" << endl;
                }
                bool found = false;
                if (last->data == num){
                    found =true;
                }
                ptr = head;
                while (ptr != last && found == false)
                {
                    if (ptr->data == num)
                    {
                        found = true;
                    }
                    ptr = ptr->next;
                }
                if (found){
                    cout << "Integer already exists." << endl;
                }
                if (!found)
                {
                    Node *newNode = new Node;
                    if (num > last->data)
                    {
                        newNode->data = num;
                        newNode->prev = last;
                        newNode->next = nullptr;
                        last->next = newNode;
                        last = newNode;
                        if (num % 2 == 0)
                        {
                            newNode->prevOddEven = lastEven;
                            lastEven->nextOddEven = newNode;
                            newNode->nextOddEven = nullptr;
                            lastEven = newNode;
                        }
                        if (num % 2 != 0)
                        {
                            newNode->prevOddEven = lastOdd;
                            lastOdd->nextOddEven = newNode;
                            newNode->nextOddEven = nullptr;
                            lastOdd = newNode;
                        }
                    }
                    else if (num < head->data)
                    {
                        newNode->data = num;
                        newNode->prev = nullptr;
                        newNode->next = head;
                        head->prev = newNode;
                        head = newNode;
                        if (num % 2 == 0)
                        {
                            newNode->prevOddEven = nullptr;
                            newNode->nextOddEven = headEven;
                            headEven->prevOddEven = newNode;
                            headEven = newNode;
                        }
                        if (num % 2 != 0)
                        {
                            newNode->nextOddEven = headOdd;
                            newNode->prevOddEven = nullptr;
                            headOdd->prevOddEven = newNode;
                            headOdd = newNode;
                        }
                    }
                    else
                    {
                        lastPtr = head;
                        ptr = lastPtr->next;
                        while (ptr->data < num)
                        {
                            lastPtr = lastPtr->next;
                            ptr = ptr->next;
                        }
                        
                        newNode->data = num;
                        newNode->next = ptr;
                        ptr->prev = newNode;
                        newNode->prev = lastPtr;
                        lastPtr->next = newNode;
                        if (num % 2 == 0)
                        {
                            if (newNode->data > lastEven->data){
                                newNode->prevOddEven = lastEven;
                                lastEven->nextOddEven = newNode;
                                newNode->nextOddEven = nullptr;
                                lastEven = newNode;
                            }
                            else if (newNode->data < headEven->data){
                                newNode->nextOddEven = headEven;
                                headEven->prevOddEven = newNode;
                                newNode->prevOddEven = nullptr;
                                headEven = newNode;
                            }
                            else{
                                ptrEven = headEven->nextOddEven;
                                lastPtrEven = headEven;
                                while (ptrEven->data < num)
                                {
                                    ptrEven = ptrEven->nextOddEven;
                                    lastPtrEven = lastPtrEven->nextOddEven;
                                }
                           
                                newNode->nextOddEven = ptrEven->nextOddEven;
                                ptrEven->prevOddEven = newNode;
                                newNode->prevOddEven = lastPtrEven;
                                lastPtrEven->nextOddEven = newNode;
                            }
                        }
                        if (num % 2 != 0)
                        {
                            if (newNode->data > lastOdd->data){
                                newNode->prevOddEven = lastOdd;
                                lastOdd->nextOddEven = newNode;
                                newNode->nextOddEven = nullptr;
                                lastOdd = newNode;
                            }
                            else if (newNode->data < headOdd->data){
                                newNode->nextOddEven = headOdd;
                                headOdd->prevOddEven = newNode;
                                newNode->prevOddEven = nullptr;
                                headOdd = newNode;
                            }
                            else{
                                ptrOdd = headOdd->nextOddEven;
                                lastPtrOdd = headOdd;
                                while (ptrOdd->data < num)
                                {
                                    ptrOdd = ptrOdd->nextOddEven;
                                    lastPtrOdd = lastPtrOdd->nextOddEven;
                                }

                                newNode->nextOddEven = ptrOdd;
                                ptrOdd->prevOddEven = newNode;
                                newNode->prevOddEven = lastPtrOdd;
                                lastPtrOdd->nextOddEven = newNode;
                            }
                        }
                    }
                }
                length++;
                break;
            }
//Delete items:
            case 5:
            {
                cout << "Enter an integer to delete:" << endl;
                while (!(cin >> num))
                {
                    cin.clear();
                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   cout << "Please enter an invalid integer:" << endl;
                }
                Node *newNode = new Node;
                bool found = false;
                if (last->data == num)
                {
                    newNode = last;
                    last = last->prev;
                    if (newNode->data % 2 == 0 ){
                        lastEven = lastEven->prevOddEven;
                    }
                    if (newNode->data % 2 != 0){
                        lastOdd = lastOdd->prevOddEven;
                    }
                    newNode->prev->next = nullptr;
                    newNode->prevOddEven->nextOddEven = nullptr;
                    length--;

                    delete newNode;
                    newNode = nullptr;
                }
                else if (head->data == num)
                {
                    newNode = head;
                    head = head->next;
                    newNode->next->prev = nullptr;
                    if (newNode->data % 2 == 0){
                        headEven = headEven->nextOddEven;
                    }
                    if (newNode->data % 2 != 0){
                        headOdd = headOdd->next;
                    }
                    newNode->nextOddEven->prevOddEven = nullptr;
                    length--;
                    delete newNode;
                    newNode = nullptr;
                }
                else
                {
                    newNode = head;
                    while (newNode->data != num && newNode != last)
                    {
                        newNode = newNode->next;
                    }
                    if (newNode != last)
                    {
                        newNode->next->prev = newNode->prev;
                        newNode->prev->next = newNode->next;
                        if (newNode->nextOddEven != nullptr){
                            
                            newNode->nextOddEven->prevOddEven = newNode->prevOddEven;
                        }
                        else{
                            if (newNode->data % 2 == 0){
                                lastEven = lastEven->prevOddEven;
                            }
                            if (newNode->data % 2  != 0){
                                lastOdd = lastOdd->prevOddEven;
                            }
                        }
                        if (newNode->prevOddEven != nullptr){
                            newNode->prevOddEven->nextOddEven = newNode->nextOddEven;
                        }
                        else{
                            if (newNode->data % 2 == 0){
                                headEven = headEven->prevOddEven;
                            }
                            if (newNode->data % 2 != 0){
                                headOdd = headOdd->prevOddEven;
                            }
                        }
                        length--;
                        delete newNode;
                        newNode = nullptr;
                    }
                    else
                    {
                        cout << "Integer not found." << endl;
                    }
                }
                break;
            }
//Exit program
            case 6:
            {
                cout << endl;
                cout << "**Goodbye.**" << endl;
                Node* newNode = new Node;
                ptr = head;
                while (ptr != last){
                    newNode = ptr;
                    ptr = ptr->next;
                    delete newNode;
                }
                newNode = nullptr;
                delete last;
                last = nullptr;
                ptr = nullptr;
                lastPtr = nullptr;
                head = nullptr;
                last = nullptr;
                headOdd = nullptr;
                lastOdd = nullptr;
                headEven = nullptr;
                ptrOdd = nullptr;
                lastPtrOdd = nullptr;
                ptrEven = nullptr;
            }
            }
        }
    }
}
