#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node* nextOddEven;
    Node* prevOddEven;
};