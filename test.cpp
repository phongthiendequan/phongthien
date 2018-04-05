#include<iostream>
#include<fstream>
void writeFile(char*a,int*data)
{
    ofstream outfile;
    outfile.open("sudokuUpdate.txt", ios::out | ios::trunc );
    for(int=0;i<9;i++)
        for(int j=0;j<9;j++)
        *(data+9*i+j) >>file;
        outfile.close();
}
