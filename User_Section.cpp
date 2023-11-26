#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <limits>

using namespace std;
int totalamount(int, int);
void deleteUserdata(int);
void deleteroom(int);
void againopenandclosefile();
void closeandopenforuserfile();
void roomAllocandDealloc(int, int);
int roomCodeChecker();
void usermenu();
void check_in();
void check_out();
int intvalidater();
void smile();
void displayTable();
void edit(int);

// Room class
// class Room
// {
// public:
//     char roomtype[50];
//     int rcode;
//     bool flag;
//     int price;
//     float discount;
//     float VAT;
//     void input()
//     {
//         flag = false;
//         int choice, n;
//         cout << "Enter Room type: ";
//         cin.getline(roomtype, 50);
//         cout << "Enter Room  code: ";
//         cin >> rcode;
//         cout << "Enter Room price: ";
//         cin >> price;
//         cout << "Enter Discount percentage: ";
//         cin >> discount;
//         cout << "Enter VAT percentage: ";
//         cin >> VAT;
//     }
//     void actualedit(int);
//     void display()
//     { int i=1;
//         cout << "|  "<<i<<" |   "<<setw(5)<<rcode<<"     |   "<<setw(12)<<roomtype<<"        |  "<<setw(6)<<price<<"  |   "<<setw(5)<<discount<<"    | "<<setw(5)<<VAT<<"|" << endl;
//     }
//     int rocode()
//     {
//         return rcode;
//     }
//     float retDiscount()
//     {
//         return discount;
//     }
//     int retPrice()
//     {
//         return price;
//     }
//     float retVat()
//     {
//         return VAT;
//     }
//     char *retRoomtype()
//     {
//         return roomtype;
//     }
//     void flagon()
//     {
//         flag = true;
//     }
//     void flagoff()
//     {
//         flag = false;
//     }
// };

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
    int roomTypeChecker(char *);
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
    cin >> rcode;
    cout << "Inisde incode" << endl;
}

int Room::roomTypeChecker(char g[50])
{
    Room R, temp;
    char *f;
    int flag = 0;

    fstream file("Room.txt", ios::binary | ios::in | ios::out);

    while (file.read(reinterpret_cast<char *>(&R), sizeof(Room)))
    {
        f = R.retRoomtype();
        if (strcmp(f, g) == 0)
        {
            flag = 1;
            cout << "\nRoomType already exists" << endl;
            temp = R;
            break;
        }
    }

    file.close(); // Close the file before further operations

    if (flag == 1)
    {
        cout << "Enter the room code: ";
        temp.inCode();
        file.open("Room.txt", ios::binary | ios::in | ios::out | ios::app);
        file.write(reinterpret_cast<char *>(&temp), sizeof(Room));
        file.close();
        return 1;
    }
    else
    {
        return 2;
    }
}

void Room::display(int i)
{
    // int i = 1;
    cout << "|  " << i << " |   " << setw(5) << rcode << "     |   " << setw(12) << roomtype << "        |  " << setw(6) << price << "  |   " << setw(5) << discount << "    | " << setw(5) << VAT << "|" << endl;
}
void Room::displayfeat()
{
    int r = 0;
    cout << "The Features are: " << endl;
    for (int i = 0; i < nFeat; i++)
    {

        cout << "5" << i + 1 << '.' << features[i] << "\t";
        r++;
        if (r > 5)
        {

            cout << "\n";
            r = 0;
        }
    }
    cout << endl;
}
int Room::input()
{
    int r;
    flag = 1;
    cout << "\n\t\t\t\tEnter Room type: ";
    cin.getline(roomtype, 50);
    r = roomTypeChecker(roomtype);
    if (r == 1)
    {
        cout << "reached the input after returning 1 ";
        return 1;
    }
    else if (r == 2)
    {
        cout << "\t\t\t\tEnter Room  code: ";
        rcode = intvalidater();
        cout << "\t\t\t\tEnter Room price(only numeric term allowed): ";
        price = intvalidater();
        cout << "\t\t\t\tEnter Discount percentage(only numeric term allowed): ";
        discount = intvalidater();
        cout << "\t\t\t\tEnter VAT percentage(only numeric term allowed): ";
        VAT = intvalidater();
        cout << "\t\t\t\tEnter the number of features: ";
        nFeat = intvalidater();
        cout << "\t\t\t\tEnter the features:" << endl;
        cin.ignore();
        for (int i = 0; i < nFeat; i++)
        {
            cout << "\t\t\t\t" << i + 1 << '.';
            cin.getline(features[i], 50);
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
            a = getch();
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
            a = getch();
            if (a == 'y' || a == 'Y')
            {
                price = tpri;
                flag = 1;
                break;
            }
        }
    }
    case 3:
    {
        while (true)
        {
            cout << "\n\t\t\t\tEnter the new discount percentage :";
            cin >> tdis;
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            a = getch();
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
            a = getch();
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
        int cFe, s = 0, c;
        do
        {
            displayfeat();
            cout << "Enter your feature choice:";
            cin >> cFe;
            cFe = cFe - 50;
            cin.ignore();
            for (int i = 0; i < nFeat; i++)
            {
                if (cFe == i + 1)
                {
                    cout << "Enter the new feature: ";
                    cin.getline(features[i], 50);
                }
                //   strncpy(t[i],r[i],sizeof(t[i]-1));
                //   t[i][sizeof(t[i]) - 1] = '\0'
                // else{
                //     cout<<"Source strlength is greater than destination length";

                // }
            }
            cout << "Enter 1 to change another feature:";
            cin >> c;
            if (c == 1)
            {
                s = 1;
            }
            else
                break;
        } while (s == 1);
        flag = 1;
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

// User class
class User
{
private:
    int roomCode;
    char name[50];
    char address[50];
    int age;

public:
    // Member function to take input for data members
    void inputData()
    {
        char c;
    repeat:
        cout << "\n\t\t\t\t Enter Room Code: ";
        roomCode = roomCodeChecker();

        cout << "\n\t\t\t\t Enter Name: ";
        cin.ignore(); // Ignore any previous newline character
        cin.getline(name, 50);

        cout << "\n\t\t\t\t Enter Address: ";
        cin.getline(address, 50);

        cout << "\n\t\t\t\t Enter Age: ";
        age = intvalidater();
        cout << "\n\n\t\t\t\t Please !! Review your data";
        cout << "\n\t\t\t\t Enter 'Y' or 'y'  to confirm it: ";
        cin >> c;
        if (c == 'Y' || c == 'y')
        {
            while (true)
            {
                if (age < 18)
                {
                    cout << "\n\t\t\t\t Age is invalid!! \n\t\t\t\t Re-enter the age: ";
                    cin >> age;
                }
                else
                    break;
            }
            roomAllocandDealloc(roomCode, 1);
        }
        else
            goto repeat;
    }

    // Member function to display user information
    void displayData()
    {
        cout << "\nRoom Code: " << roomCode << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
        cout << "\n";
    }
    char *retName()
    {
        return name;
    }
    char *retAddress()
    {
        return address;
    }
    int roCode()
    {
        return roomCode;
    }
};

int main()
{
    int choice;
    while (true)
    {
        usermenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            check_in();
            cout << "\n\t\t\t\t Valid age" << endl;
            cout << " \n\t\t\t\t User checked-in successfull !!";
            smile();
            getch();
            break;
        }
        break;
        case 2:
        {
            system("cls");
            check_out();
            cout << "\n\n\t\t\t\t User checked-out successfull !!"<<endl;
            cout << "\n\t\t\t\t Thank you for the stay!! "<<endl;
            cout << "\n\t\t\t\t We are exiting.";
            smile();
            exit(0);
            break;
        }
        case 3:
        {
            // cout << "\nYetikae dummy case banayeko maile";
            exit(0);
            break;
        }
        case 4:
        {
            system("cls");
            ifstream inputFile("UserRecordsFile.txt", ios::binary | ios::in);
            if (!inputFile.is_open())
            {
                cout << "Error opening file for reading!" << endl;
                return 1;
            }
            User obj;
            while (inputFile.read((char *)&obj, sizeof(User)))
            {
                obj.displayData();
            }
            inputFile.close();
            getch();
            break;
        }
        case 5:
        {
            system("cls");
            int r;
            cout << "Enter the roomcode";
            cin >> r;
            deleteUserdata(r);
            break;
        }

        default:
            cout << "\nPlease try again";
            break;
        }
    }

    return 0;
}

// Display of the room info ..
void displayTable()
{
    cout << "\n\n\n\n\t\t\tThese are all the room\n";
    cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
    cout << "| S.N|    Room code |        Room type     |   Price   | Discount | VAT   |" << endl;
    cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
    ifstream inputFile("Room.txt", ios::binary | ios::in);
    if (!inputFile.is_open())
    {
        cout << "Error opening file for reading!" << endl;
        return;
    }
    Room room;
    int i = 0;
    while (inputFile.read(reinterpret_cast<char *>(&room), sizeof(Room)))
    {
        i++;
        room.display(i);
        room.displayfeat();
    }
    inputFile.close();
    cout << "\n\n";
}

// Smile animation function
void smile()
{
    char g[6][9] = {{' ', ' ', '*', '*', '*', '*', '*', ' ', ' '},
                    {' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' '},
                    {'*', ' ', ' ', 'O', ' ', 'O', ' ', ' ', '*'},
                    {'*', ' ', ' ', ' ', '^', ' ', ' ', ' ', '*'},
                    {' ', '*', ' ', '\\', '_', '/', ' ', '*', ' '},
                    {' ', ' ', '*', '*', '*', '*', '*', ' ', ' '}

    };

    std::cout << "\n"; 
    for (int i = 0; i < 6; i++)
    {
        std::cout << "\t\t\t\t\t";
        for (int j = 0; j < 9; j++)
        {
            std::cout << g[i][j];
            Sleep(100);
        }
        std::cout << "\n";
    }
}

void check_in()
{
    
    cout<<"\t\t\t\t Check-in Page "<<endl;
    User user1;
    user1.inputData();
    ofstream writeFile;
    writeFile.open("UserRecordsFile.txt", ios::binary | ios::app | ios::out);
    if (!writeFile.is_open())
    {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    writeFile.write((char *)&user1, sizeof(User));
    writeFile.close();
}

void check_out()
{   
    cout<<"\n\t\t\t\t Check-out Page ";
    int RoCode, lamount, pay, lmoney = 0, totalprice;
    int tempprice;
    float tempdis, tempvat;
    char temprotype[50];
    char tempGname[50], tempAddress[50];
    cout << "\nEnter the roomcode: ";
    cin >> RoCode;
    Room tobj;    // tobj=Temporary object
    User dispobj; // dispobj=object being used for the display
    ifstream infile("Room.txt", ios::binary | ios::in);
    ifstream infile1("UserRecordsFile.txt", ios::binary | ios::in);
    if (!infile.is_open())
    {
        cout << "\nError: Unable to open the room file";
        exit(0);
    }
    else if (!infile1.is_open())
    {
        cout << "\nError: Unable to open the room file";
        exit(0);
    }

    // reading from the roomfile and getting the desired data is done here
    while (infile.read((char *)&tobj, sizeof(Room)))
    {
        if (RoCode == tobj.rocode())
        {
            // cout << "\nRoom file ma room vetiyo";
            tempprice = tobj.retPrice();
            tempdis = tobj.retDiscount();
            tempvat = tobj.retVat();
            strcpy(temprotype, tobj.retRoomtype());
        }
    }
    // reading from the userfile and getting the desired data is done here
    while (infile1.read((char *)&dispobj, sizeof(User)))
    {
        if (RoCode == dispobj.roCode())
        {
            // cout << "\nUser ko ma pani room vetiyo";
            strcpy(tempGname, dispobj.retName());
            strcpy(tempAddress, dispobj.retAddress());
        }
    }
    infile.close();
    infile1.close();
    cout << "\n\t\t\t\t[1] Guest name: " << tempGname;
    cout << "\n\t\t\t\t[2] Address: " << tempAddress;
    cout << "\n\t\t\t\t[3] Room type: " << temprotype;
    cout << "\n\t\t\t\t[4] Price: " << tempprice;

    // calculation part
    // 1st parameter =price and 2nd paramter=total days stayed here 4 is dummy value
    totalprice = totalamount(tempprice, 4);
    totalprice = totalprice + (totalprice * (tempvat / 100)) - (totalprice * (tempdis / 100));
    cout << "\n\n\t\t\t\tTotal amount: " << totalprice;

    cout << "\n\t\t\t\tPlease enter amount to be paid: ";
    cin >> pay;
// This lable is to recheck whether the amount is fully paid after left money is added
check:
    pay += lmoney;
    lamount = pay - totalprice;
    if (lamount < 0)
    {
        cout << "\n\t\t\t\tNot enough amount !! " << endl;
        cout << "\t\t\t\The remaning money to pay: " << lamount << endl;
        cout << "\t\t\t\tPlease enter the remaning amount: ";
        cin >> lmoney;
        goto check;
    }
    else if (lamount > 0)
    {
        cout << "\n\t\t\t\tYour return amount is:" << lamount;
    }
    deleteUserdata(RoCode);
    roomAllocandDealloc(RoCode, 0);
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

void usermenu()
{
    system("cls");
    cout<<"\n\n\t\t\t\tRoom Management menu "<<endl;

    cout << "\n\t\t\t\t 1.Check-in";
    cout << "\n\t\t\t\t 2.Check-out";
    cout << "\n\t\t\t\t 3.Exit";
    cout << "\n\t\t\t\t 4.Display the data in the file";
    cout << "\n\t\t\t\t 5.Delete the data";
    cout << "\n\n\t\t\t\t Enter your choice: ";
}

// Function to check the room code if it is already reserved or not.
int roomCodeChecker()
{
    int flag, t;

    do
    {
        User C;
        flag = 0;
        cin >> t;
        fstream file;
        file.open("UserRecordsFile.txt", ios::binary | ios::in | ios::out);
        if (!file.is_open())
        {
            file.open("UserRecordsFile.txt", ios::binary | ios::out);
            if (!file.is_open())
            {
                cerr << "Error opening the file" << endl;
                exit(0);
            }
        }
        while (file.read((char *)&C, sizeof(User)))
        {
            if (t == C.roCode())
            {
                cout << "Room code is reserved" << endl;
                flag = 1;
                cout << "Enter the room code again: ";
                break;
            }
        }
        file.close();

    } while (flag != 0);

    return t;
}

void roomAllocandDealloc(int n, int sw)
{
    Room st, tmp;
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
                // cout << "\nRoom found";
                flag = 1;
                fpos = (int)file.tellg();
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Room doesn't exist for allocation";
            cin.get();
            exit(0);
        }
        file.seekp(fpos - sizeof(Room), ios::beg);
        tmp = st;
        if (sw == 1)
        {
            tmp.flagon();
        }
        else
        {
            tmp.flagoff();
        }

        file.write((char *)&tmp, sizeof(Room));
        file.close();
    }
}

// UserRecordsFile.txt
void closeandopenforuserfile()
{
    ifstream inFile;
    User aa;
    inFile.open("UserRecordsFile.txt", ios::binary);
    if (!inFile)
    {
        cin.get();
        return;
    }
    while (inFile.read((char *)&aa, sizeof(User)))
    {
    }
    inFile.close();
}

// Room.txt refresh file
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

// Room deletion function
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

void deleteUserdata(int n)
{
    User del, hh;
    int flag = 0;
    ifstream infile("UserRecordsFile.txt", ios::binary);
    ofstream outfile("tmp.txt", ios::binary);
    if (!infile)
    {
        cout << "\nRoom.txt is not opening" << endl;
        cin.get();
        return;
    }
    else if (!outfile)
    {
        cout << "tmp.txt is not opening";
        cin.get();
        return;
    }
    else
    {
        infile.seekg(0, ios::beg);
        while (infile.read((char *)&hh, sizeof(User)))
        {
            if (n == hh.roCode()) // Checking the existence of user
            {
                // cout << "\nUser exist;";
                flag = 1;
                infile.seekg(0, ios::beg);
                // Writing of content in temp file starts here
                //  logic used: Writing all the content except deleting content in temp file and renaming the temp file to original file.
                while (infile.read((char *)&del, sizeof(User)))
                {
                    if (n != del.roCode())
                    {
                        outfile.write((char *)&del, sizeof(User));
                    }
                }
            }
        }
        if (flag == 0)
        {
            cout << "User doesn't exist";
            cin.get();
            return;
        }
    }
    outfile.close();
    infile.close();
    remove("UserRecordsFile.txt");
    rename("tmp.txt", "UserRecordsFile.txt");
    closeandopenforuserfile();
}

// Function to calculate total money of the bill
int totalamount(int price, int days)
{

    return (price * days);
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

// File that we are creating is UserRecordsFile.txt
