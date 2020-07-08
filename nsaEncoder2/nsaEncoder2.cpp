
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string getFileName();

const int SIZE = 5;
int r() {
    int n = 1 + rand() % 20;
    return n;
}
void offset(int &arr, int size) {
    




    
}


int main()
{
    srand(time(0));

    string objective = "Encode any string entered by adding 1 to the ASCII value, outputs to secret.txt";
    string instructions = "";
    string fileName;
    ifstream fin;
    ofstream fout;
    string line;
    int lineNumber = 0;
    ofstream off;
    string output = "secret.txt";
    string offset = "offset.txt";

    int counter = 0;
    int arr[SIZE];
    int index;
    for (int i = 0; i < SIZE; i++) {

        arr[i] = r();

    }

    off.open(offset.c_str());
    for (int i = 0; i < SIZE; i++) {

        off << arr[i] << endl;


    }
    off.close();
    fileName = getFileName();
    fin.open(fileName.c_str());
    fout.open(output.c_str());
    if (!(fin.good())) throw "I/O error";


    while (fin.good())
    {
        lineNumber = lineNumber + 1;
        getline(fin, line);
        for (int i = 0; i < line.length(); i++) {
            index = counter % SIZE;
            line[i] = line[i] - arr[index];
            counter++;
        }



        fout << line << endl;
        cout << line << endl;
        
    }

}



string getFileName()
{

    string fN;


    do
    {
        cout << "Please enter an input filename [i.e.: x.txt]: ";
        getline(cin, fN);
    } while (!(fN.length() >= 5));
    return fN;
}