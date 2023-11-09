#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include<iomanip>
#include<limits>
using namespace std;
int intvalidater()
{
 int r;
 cin>>r;
    while(1)
{
if(cin.fail())
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<"Enter the numbers only"<<endl;
cin>>r;
}
if(!cin.fail())
break;
}

//cout<<"the number is: "<<r<<endl;
return r;
}
class Room
{

    char roomtype[50];
    int rcode;
    bool flag;
    int price;
    float discount;
    float VAT; 
    public:
    void input()
    {
        flag = false;
        int choice, n;
        cout << "\n\t\t\t\tEnter Room type: ";
        cin.getline(roomtype, 50);
        cout<<"";
        cout << "\t\t\t\tEnter Room  code: ";
        cin>>rcode;
        cout << "\t\t\t\tEnter Room price(only numeric term allowed): ";
         price=intvalidater();
        cout << "\t\t\t\tEnter Discount percentage(only numeric term allowed): ";
         discount=intvalidater();
        cout << "\t\t\t\tEnter VAT percentage(only numeric term allowed): ";
        VAT=intvalidater();
    }
    void actualedit(int);
    void display()
    { int i=1;
        cout << "|  "<<i<<" |   "<<setw(5)<<rcode<<"     |   "<<setw(12)<<roomtype<<"        |  "<<setw(6)<<price<<"  |   "<<setw(5)<<discount<<"    | "<<setw(5)<<VAT<<"|" << endl;
        // cout << "\n\t\t\t\tRoom code: " << rcode << endl;
        // cout << "\t\t\t\tRoom type: " << roomtype << endl;
        // cout << "\t\t\t\tPrice: " << price << endl;
        // cout << "\t\t\t\tVAT: " <<VAT <<endl;
        // cout << "\t\t\t\tDiscount: " <<discount<<endl;
        // cout<< "\n";
    }
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
};
void smile()
{
    cout << "  *****" << endl;
    cout << " *     *" << endl;
    cout << "*  O O  *" << endl;
    cout << "*   ^   *" << endl;
    cout << " * \\_/ *" << endl;
    cout << "  *****" << endl;
}

void Room::actualedit(int n)
{
    int op;
    char  rtype[50],a;
    int tpri;
    float tdis, tvat;
again:
    bool flag = 0; 
    cout << "\n\n\n\n\t\t\t\t  Room id:" << n << endl;
    cout << "\t\t\t\t1.Room type:" << roomtype << endl;
    cout << "\t\t\t\t2.Price:" << price << endl;
    cout << "\t\t\t\t3.Discount percentage " << discount << endl;
    cout << "\t\t\t\t4.VAT percentage " << VAT << endl;
    cout << "\t\t\t\tEnter the number to change the specific option:";
    cin >> op;
    switch (op)
    {
    case 1:
    {
        while (true)
        { cin.ignore();
            cout << "\n\t\t\t\tEnter the new room type :";
            std::cin.getline(rtype,50);
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            a = getch();
            if (a == 'y' || a =='Y')
            {
                strcpy(roomtype,rtype);
                flag = 1;
                break;
            }
        }
        break;
    }
    case 2:
    {
        while(true)
        {cout << "\n\t\t\t\tEnter the new price :";
        cin >> tpri;
        cout << "\t\t\t\tPress y to confirm and n to change again: ";
        a = getch();
         if (a == 'y' || a=='Y')
        {
            price = tpri;
            flag = 1;
            break;
        }}
    }
    case 3:
    {
        while (true)
        {
            cout << "\n\t\t\t\tEnter the new discount percentage :";
            cin >> tdis;
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            a = getch();
            if (a == 'y' || a=='Y')
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
            a = getch();
            if (a == 'y' || a=='Y')
            {
                VAT = tvat;
                flag = 1;
                break;
            }
        }
        break;
    }
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
        else return;
    }
}

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
                cout << "room exist;";
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
    cout << "\n\t\t\t\t------------Room deleted successfully------------" << endl;
    smile();
    getch();
}
int main()
{
    int choice;
    int roomid;
    while (true)
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\tMenu:\n";
        cout << "\t\t\t\t1. Add Room \n";
        cout << "\t\t\t\t2.Edit Room \n";
        cout << "\t\t\t\t3.Display Room data\n";
        cout << "\t\t\t\t4.Delete Room \n";
        cout << "\t\t\t\t5. Exit\n";
        cout << "\t\t\t\tEnter your choice: ";

        cin >> choice;
        cin.ignore(); // Clear the newline character left in the buffer
        switch (choice)
        {
        case 1:
        {
            Room Room1;
            cout<<"\n\t\t\t\t Room addition";
            Room1.input();

            ofstream outputFile("Room.txt", ios::binary | ios::app | ios::out);
            if (!outputFile.is_open())
            {
                cout << "Error opening file for writing!" << endl;
                return 1;
            }

            outputFile.write(reinterpret_cast<const char *>(&Room1), sizeof(Room));
            outputFile.close();
            cout << "Room data added successfully." << endl;
            getch();
            break;
        }
        case 2:
        {
            cout<<"\n\n\n\n\t\t\t\tEdit room";
            cout << "\n\t\t\t\tEnter the room id:";
            cin >> roomid;
            edit(roomid);
            break;
        }
        case 3:
        {   cout<<"\n\n\n\n\t\t\tThese are all the room\n";
        cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
    cout << "| S.N|    Room code |        Room type     |   Price   | Discount | VAT   |" << endl;
    cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
            ifstream inputFile("Room.txt", ios::binary);
            if (!inputFile.is_open())
            {
                cout << "Error opening file for reading!" << endl;
                return 1;
            }
            Room room;
            while (inputFile.read(reinterpret_cast<char *>(&room), sizeof(Room)))
            {
                room.display();
            }
            inputFile.close();
            getch();
            break;
        }
        case 4:
        {   cout<<"\n\n\n\n\nDelete room ";
            cout << "\n\t\t\t\tEnter the room id";
            cin >> roomid;
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
        //cout<<"Compiler";
    }
    return 0;
}


/* Output:-
Value of flag will determine whether it is allocated or not.





*/
