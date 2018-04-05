#include"myFunctionData.h"
void changeIntergerToString(string *a,int*sudokuUpdate)
{
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
   {

      *(a+i*9+j)=to_string(*(sudokuUpdate+i*9+j));
   }

}
bool checkAddNumber(int x,int y,int *sudokuBegin )
{
  return (*(sudokuBegin+(y-100)*9/40+(x-100)/40)==0?true : false);
}
void loadData(int *sudokuUpdate, string a)
{
    ifstream file(a.c_str());
    file.is_open();
   for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
   {
      file>> *(sudokuUpdate+9*i+j);
   }

}
void  createSudoku(int *sudokuUpdate,int *sudokuCheck,int k)
{
    srand(time(NULL));
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
    {
        int m=rand()%9;
        int n= rand()%9;
        if(*(sudokuUpdate+9*m+n)!=0) *(sudokuUpdate+9*m+n)=0;
        else
         j--;

    }
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
    {

        *(sudokuCheck+9*i+j)=*(sudokuUpdate+9*i+j);
    }

}
bool checkWin(int *sudokuUpdate,int *sudokuResult )
{

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(*(sudokuResult+9*i+j)!=*(sudokuUpdate+9*i+j))
            {
               return false;

            }
        }
    return true;
}
void check3x3(int x,int y,int *sudokuUpdate,int *sudokuZero)
{
    for(int i=x;i<x+3;i++)
        for(int j=y;j<y+3;j++)
    {

       for(int m=x;m<x+3;m++)
        for(int n=y;n<y+3;n++)
        if(*(sudokuUpdate+9*i+j)!=0&&*(sudokuUpdate+9*i+j)==*(sudokuUpdate+9*m+n)&&(9*i+j!=9*m+n))
        *(sudokuZero+9*i+j) =1;
    }
}
void checkfull(int *sudokuUpdate,int *sudokuZeRo)
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
    {
        *(sudokuZeRo +9*i+j)=0;
    }
   for(int i=0;i<9;i++)
       for(int j=0;j<9;j++)
        for(int k=0;k<9;k++)
 {
        if(*(sudokuUpdate+9*i+j)!=0&&*(sudokuUpdate+9*i+j)==*(sudokuUpdate+9*i+k)&&(9*i+j!=9*i+k))
        {
            *(sudokuZeRo+9*i+j) =1;
        }
    }
    for(int i=0;i<9;i++)
      for(int j=0;j<9;j++)
        for(int k=0;k<9;k++)
    {
        if(*(sudokuUpdate+9*j+i)!=0&&*(sudokuUpdate+9*j+i)==*(sudokuUpdate+9*k+i)&&(9*j+i!=9*k+i))
        {
            *(sudokuZeRo+9*j+i) =1;

       }
    }
    for(int i=0;i<9;i=i+3)
        for(int j=0;j<9;j=j+3)
    check3x3(i,j,sudokuUpdate,sudokuZeRo);


    }
void changeSudoku(int *sudokuUpdate,int *sudokuCheck,int *sudokuResult)
{
    string a[3] ={"level_1.txt","level_2.txt","level_3.txt"};
    srand(time(NULL));
	int i = rand()%3;

    loadData(sudokuUpdate,a[i]);
    createSudoku(sudokuUpdate,sudokuCheck,1);
    loadData(sudokuResult,a[i]);
}
void writeFile(string a,int*data)
{
    ofstream outfile;
    outfile.open(a.c_str(), ios::out | ios::trunc );
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        outfile<<*(data+9*i+j) <<" ";
        outfile<<endl;
    }

        outfile.close();
}
