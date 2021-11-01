//sudokutest.cpp

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios_base;
#include "sodu.h"
#include <Windows.h>

int main()
{
    //Ô¤ÏÈ²âÊÔÎÄ¼ş
    cout << "Opening \"sudoku.txt\"" << endl;
    ifstream infile;
    infile.open("sudoku.txt");
    if (infile.fail())
    {
        cout << "Fail opening \"sudoku.txt\"" << endl;
        system("pause");
        return 0;
    }
    infile.close();

    sudoku n;

    if (!n.checksudoku())
    {
        cout << "Illegal sudo!" << endl;
        system("pause");
        return 0;
    }

    n.printsudo();
    cout << endl;

    n.solve();

    cout << "Answer" << endl;
    n.printsudo();

    n.outputsudoku();

    system("pause");
    return 0;
}