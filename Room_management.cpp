#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include<windows.h>
#include <limits>
using namespace std;
int intvalidater();
void smile();
void edit(int);
void againopenandclosefile();
void deleteroom(int);
void displayTable();
void roommenu();


     

class Room
{

    char roomtype[50];
    int rcode;
    bool flag;
    int price;
    float discount;
    float VAT;
    char features[20][50];
    int nFeat;

public:
 int roomTypeChecker( char*);
     int input();
    void inCode();
    void actualedit(int);
    void display(int);
    void displayfeat();

    int rocode()
    {
        return rcode;
    }
    float retDiscount()
    {
        return discount;
    }
    int retPrice()
    {
        return price;
    }
    float retVat()
    {
        return VAT;
    }
    char *retRoomtype()
    {
        return roomtype;
    }
    void flagon()
    {
        flag = true;
    }
    void flagoff()
    {
        flag = false;
    }
    bool retFlag()
    {
        return flag;
    }
};

void Room::inCode()
{
    cin>>rcode;
    cout<<"Inisde incode"<<endl;
}
int Room::roomTypeChecker( char g[50]) {
    Room R, temp;
    char* f;
    int flag = 0;

    fstream file("Room.txt", ios::binary | ios::in | ios::out);
    
    while (file.read(reinterpret_cast<char*>(&R), sizeof(Room))) {
        f = R.retRoomtype();
        if (strcmp(f, g) == 0) {
            flag = 1;
            cout << "\t\t\t\tRoomType already exists !" << endl;
            temp = R;
            break;
        }
    }

    file.close();  // Close the file before further operations
    
    if (flag == 1) {
        cout << "\t\t\t\tEnter the room code: ";
        temp.inCode();
         file.open("Room.txt", ios::binary | ios::in | ios::out | ios::app);
        file.write(reinterpret_cast<char*>(&temp), sizeof(Room));
        file.close();
        return 1;
    } else {
        return 2;
    }
}



void Room::display(int i)
{
     //int i = 1;
        cout << "|  " << i << " |   " << setw(5) << rcode << "     |   " << setw(12) << roomtype << "        |  " << setw(6) << price << "  |   " << setw(5) << discount << "    | " << setw(5) << VAT << "|" << endl;
}
void Room::displayfeat()
{ int r=0;
cout<<"The Features are: "<<endl;
    for(int i=0;i<nFeat;i++)
    {
       
        cout<<"5"<<i+1<<'.'<<features[i]<<"\t";
        r++;
        if(r>5)
        {

            cout<<"\n";
            r=0;
        }
    }
    cout<<endl;
}
int Room::input()
{      
        int r;
        flag = 1;
        system("cls");
        cout << "\n\t\t\t\t Room addition"<<endl;
        cout << "\n\t\t\t\tEnter Room type: ";
        cin.getline(roomtype, 50);
        r=roomTypeChecker(roomtype);
        if(r==1)
        {
            //cout<<"reached the input after returning 1 ";
            return 1;

        }
        else if(r==2)
        {
        cout << "\t\t\t\tEnter Room  code: ";
         rcode=intvalidater();
        cout << "\t\t\t\tEnter Room price(only numeric term allowed): ";
        price = intvalidater();
        cout << "\t\t\t\tEnter Discount percentage(only numeric term allowed): ";
        discount = intvalidater();
        cout << "\t\t\t\tEnter VAT percentage(only numeric term allowed): ";
        VAT = intvalidater();
        cout<<"\t\t\t\tEnter the number of features: ";
        nFeat=intvalidater();
        cout<<"\t\t\t\tEnter the features:"<<endl;
        cin.ignore();
        for(int i=0;i<nFeat;i++)
        {
            cout<<"\t\t\t\t"<<i+1<<'.';
            cin.getline(features[i],50);
        }
        return 2;
        }
      
}

void Room::actualedit(int n)
{
    int op;
    char rtype[50], a;
    int tpri;
    float tdis, tvat;
again:
    bool flag = 0;
    cout << "\n\n\n\n\t\t\t\t  Room id:" << n << endl;
    cout << "\t\t\t\t1.Room type:" << roomtype << endl;
    cout << "\t\t\t\t2.Price:" << price << endl;
    cout << "\t\t\t\t3.Discount percentage " << discount << endl;
    cout << "\t\t\t\t4.VAT percentage " << VAT << endl;
    cout << "\t\t\t\t5.Features " << endl;
       
    
    cout << "\t\t\t\tEnter the number to change the specific option:";
    cin >> op;
    switch (op)
    {
    case 1:
    {
        while (true)
        {
            cin.ignore();
            cout << "\n\t\t\t\tEnter the new room type :";
            std::cin.getline(rtype, 50);
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            cin>>a;
            if (a == 'y' || a == 'Y')
            {
                strcpy(roomtype, rtype);
                flag = 1;
                break;
            }
        }
        break;
    }
    case 2:
    {
        while (true)
        {
            cout << "\n\t\t\t\tEnter the new price :";
            cin >> tpri;
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            cin>>a;
            if (a == 'y' || a == 'Y')
            {
                price = tpri;
                flag = 1;
                break;
            }
        }
        break;
    }
    case 3:
    {
        while (true)
        {
            cout << "\n\t\t\t\tEnter the new discount percentage :";
            cin >> tdis;
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            cin>>a;
            if (a == 'y' || a == 'Y')
            {
                discount = tdis;
                flag = 1;
                break;
            }
        }
        break;
    }
    case 4:
    {
        while (true)
        {
            cout << "\n\t\t\t\tEnter the new vat percentage :";
            cin >> tvat;
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            cin>>a;
            if (a == 'y' || a == 'Y')
            {
                VAT = tvat;
                flag = 1;
                break;
            }
        }
        break;
    }
     case 5:
     {
    int cFe,s=0,c;
    do{
    displayfeat();
    cout<<"Enter your feature choice:";
    cin>>cFe;
    cFe=cFe-50;
    cin.ignore();
            for(int i=0;i<nFeat;i++)
            {
                if(cFe==i+1)
                {
                  cout<<"Enter the new feature: ";
                  cin.getline(features[i],50);
                 
                              
                }
                //   strncpy(t[i],r[i],sizeof(t[i]-1));
                //   t[i][sizeof(t[i]) - 1] = '\0'
                // else{
                //     cout<<"Source strlength is greater than destination length";
                 
                // }
            }
             cout<<"Enter 1 to change another feature:";
                  cin>>c;
                  if(c==1)
                  {
                  s=1;
                  }
                  else 
                  break;
    }while(s==1);
    flag=1;
    break;
    }
    if (flag == 1)
    {
        char c;
        cout << "\n\t\t\t\tEnter the 'm' or 'M' to edit more: ";
        c = getch();
        if (c == 'm' || c == 'M')
        {
            goto again;
        }
        else
            return;
    }
}
}


int main()
{
    int choice,s;
    int roomid;
    while (true)
    {
        roommenu();
        cin >> choice;
        cin.ignore(); // Clear the newline character left in the buffer
        switch (choice)
        {
        case 1:
        {
            Room Room1;
            
            s=Room1.input();
            if(s==2)
            {
            ofstream outputFile("Room.txt", ios::binary | ios::app | ios::out);
            if (!outputFile.is_open())
            {
                cout << "Error opening file for writing!" << endl;
                return 1;
            }
            outputFile.write(reinterpret_cast<const char *>(&Room1), sizeof(Room));
            outputFile.close();
            cout << "\t\t\t\tRoom data added successfully." << endl;
            smile();
            getch();
            break;
            }
            else if(s==1)
            {
                cout << "\n\t\t\t\tRoom data added successfully." << endl;
                smile();
                getch();
            break;
            }
        }
        case 2:
        {
            system("cls");
            cout << "\n\n\n\n\t\t\t\tEdit room";
            cout << "\n\t\t\t\tEnter the room id:";
            cin >> roomid;
            edit(roomid);
            break;
        }
        case 3:
        {
            system("cls");
            cout << "\n\n\n\n\t\t\tThese are all the room\n";
            cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
            cout << "| S.N|    Room code |        Room type     |   Price   | Discount | VAT   |" << endl;
            cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
            ifstream inputFile("Room.txt", ios::binary|ios::in);
            if (!inputFile.is_open())
            {
                cout << "Error opening file for reading!" << endl;
                return 1;
            }
            Room room;
            int i=0;
            while (inputFile.read(reinterpret_cast<char *>(&room), sizeof(Room)))
            {   i++;
                room.display(i);
                room.displayfeat();
            }
            inputFile.close();
            getch();
            break;
        }
        case 4:
        {   
            system("cls");
            displayTable();
            cout << "\n\t\t\t\tDelete room ";
            cout << "\n\t\t\t\tEnter the room id: ";
            roomid=intvalidater();
            deleteroom(roomid);
            break;
        }
        case 5:
        {
            cout << "\t\t\t\tExiting program." << endl;
            return 0;
        }
        default:
            cout << "\t\t\t\tInvalid choice. Please select again." << endl;
        }
        // cout<<"Compiler";
    }
    return 0;
}

int intvalidater()
{
    int r;
    cin >> r;
    while (1)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\t\t\t\t\tEnter the numbers only" << endl;
            cin >> r;
        }
        if (!cin.fail())
            break;
    }
    return r;
}

// Smile animation function 
void smile()
{
     char g[6][9]={{' ',' ','*','*','*','*','*',' ',' '},
                  {' ','*',' ',' ',' ',' ',' ','*',' '},
                  {'*',' ',' ','O',' ','O',' ',' ','*'},
                  {'*',' ',' ',' ','^',' ',' ',' ','*'},
                  {' ','*',' ','\\','_','/',' ','*',' '},
                  {' ',' ','*','*','*','*','*',' ',' '}
        
    };

    std::cout << "\n";
    for (int i = 0; i < 6; i++) {
        std::cout << "\t\t\t\t";
        for (int j = 0; j < 9; j++) {
            std::cout << g[i][j];
            Sleep(100);
       
    }
     std::cout << "\n";
    }
}

//edit function
void edit(int n)
{
    Room tmp, st;
    int rid = n, flag = 0, fpos = -1;
    fstream file;
    file.open("Room.txt", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "Error opening file for editing !";
        return;
    }
    else
    {
        while (file.read((char *)&st, sizeof(Room)))
        {
            if (rid == st.rocode())
            {
                flag = 1;
                fpos = (int)file.tellg();
                break;
            }
        }
        if (flag == 0)
        {
            cout << "\t\t\t\tRoom doesn't exist";
            getch();
            return;
        }
        file.seekp(fpos - sizeof(Room), ios::beg);
        tmp = st;
        tmp.actualedit(rid);

        file.write((char *)&tmp, sizeof(Room));
        file.close();
        getch();
    }
}

// sometime files doesn't respond so opening and closing is done to make sure that.
//room file refreshing function 
void againopenandclosefile()
{
    ifstream inFile;
    Room aa;
    inFile.open("Room.txt", ios::binary);
    if (!inFile)
    {
        cin.get();
        return;
    }
    while (inFile.read((char *)&aa, sizeof(Room)))
    {
    }
    inFile.close();
}

void deleteroom(int n)
{
    Room del, hh;
    int flag = 0;
    ifstream infile("Room.txt", ios::binary);
    ofstream outfile("tmp.txt", ios::binary);
    if (!infile)
    {
        cout << "\n\t\t\t\tRoom.txt is not opening" << endl;
        cin.get();
        return;
    }
    else if (!outfile)
    {
        cout << "\t\t\t\ttmp.txt is not opening";
        cin.get();
        return;
    }
    else
    {
        infile.seekg(0, ios::beg);
        while (infile.read((char *)&hh, sizeof(Room)))
        {
            if (n == hh.rocode()) // Checking the existence of room
            {
                cout << "\t\t\t\troom exist;";
                flag = 1;
                infile.seekg(0, ios::beg);
                // Writing of content in temp file starts here
                //  logic used: Writing all the content except deleting content in temp file and renaming the temp file to original file.
                while (infile.read((char *)&del, sizeof(Room)))
                {
                    if (n != del.rocode())
                    {
                        outfile.write((char *)&del, sizeof(Room));
                    }
                }
            }
        }
        if (flag == 0)
        {
            cout << "Room doesn't exist";
            cin.get();
            getch();
            return;
        }
    }
    outfile.close();
    infile.close();    
    remove("Room.txt");
    rename("tmp.txt", "Room.txt");
    againopenandclosefile();
    cout << "\n\t\t------------Room deleted successfully------------" << endl;
    smile();
    getch();
}

void displayTable()
{
     cout << "\n\n\n\n\t\t\tThese are all the room\n";
            cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
            cout << "| S.N|    Room code |        Room type     |   Price   | Discount | VAT   |" << endl;
            cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
            ifstream inputFile("Room.txt", ios::binary|ios::in);
            if (!inputFile.is_open())
            {
                cout << "Error opening file for reading!" << endl;
                return;
            }
            Room room;
            int i=0;
            while (inputFile.read(reinterpret_cast<char *>(&room), sizeof(Room)))
            {   i++;
                room.display(i);
                room.displayfeat();
            }
            inputFile.close();
            cout<<"\n\n";

}

void roommenu()
{
            system("cls");
        cout << "\n\n\n\n\t\t\t\tMenu:\n";
        cout << "\t\t\t\t1. Add Room \n";
        cout << "\t\t\t\t2.Edit Room \n";
        cout << "\t\t\t\t3.Display Room data\n";
        cout << "\t\t\t\t4.Delete Room \n";
        cout << "\t\t\t\t5. Exit\n";
        cout << "\t\t\t\tEnter your choice: ";

}