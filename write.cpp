#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ofstream file("integer.dat");
    int array[9] = {1, 3, 4, 5, 7, 9, 10, 12, 20};
    for (int i = 0; i < 9; i++){
        file.seekp(i*sizeof(int), ios::beg);
        file.write(reinterpret_cast<char*> (&array[i]), sizeof(int));
    }
    file.close();

}