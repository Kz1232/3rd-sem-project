#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
display()
{
cout<<"\n";
int roomcode[10]={10,20,30,40,50};
float dis[6]={1.0,45.0,60.0,70.0,33.2};
float vat[6]={1.0,45.0,60.0,70.0,33.1};
//int price[7]={500,}
//char[6][50]={""};

string roomtype[6]={"kkkkk","rrrrr","yurhuhsf","rssss","jksjkfjdlasj","hueiks"};
for(int i=0;i<5;i++)
{
cout << "|  "<<i<<" |   "<<setw(5)<<roomcode[i]<<"     |   "<<setw(12)<<roomtype[i]<<"        |  "<<setw(6)<<i*100<<"  |   "<<setw(5)<<dis[i]<<"    | "<<setw(5)<<vat[i]<<"|" << endl;
}
}
int main()
{
  system("cls");
   cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
    cout << "| S.N|    Room code |        Room type     |   Price   | Discount | VAT   |" << endl;
    cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
    display();
    return 0;
}