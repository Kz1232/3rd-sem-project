#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <limits>

using namespace std;
void headanimation();
void menu();
void Firstmenu();
void Admsecondmenu();
void usermenu();
void UserDetailModiMenu();
void UserDetailModifManagement();
void roommanagement();
void usersection();
int login();
bool loginsystem();
void Register();
void smile();
void edit(int);
void deleteroom(int);
void check_in();
void check_out();
int totalamount(int, int);
void deleteUserdata(int);
void roomAllocandDealloc(int, int);
void closeandopenforuserfile();
void againopenandclosefile();
int roomCodeChecker();
int intvalidater();
void displayTable();
void editUserdata(int);

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
            cin >> a;
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
            cin >> a;
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
            cin >> a;
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
            cin >> a;
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
    void actualeditUser(int);
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
void User::actualeditUser(int n)
{
    int op;
    char tname[50], a, taddr[50];
    int tage;
again:
    bool flag = 0;
    cout << "\n\n\n\n\t\t\t\t  Room id:" << n << endl;
    cout << "\t\t\t\t1.Name: " << name << endl;
    cout << "\t\t\t\t2.Address: " << address << endl;
    cout << "\t\t\t\t3.Age: " << age << endl;
    cout << "\n\t\t\t\tEnter the number to change the specific option:";
    cin >> op;
    switch (op)
    {
    case 1:
    {
        while (true)
        {
            cin.ignore();
            cout << "\n\t\t\t\tEnter the new name :";
            std::cin.getline(tname, 50);
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            a = getch();
            if (a == 'y' || a == 'Y')
            {
                strcpy(name, tname);
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
            cout << "\n\t\t\t\tEnter the new address :";
            std::cin.getline(taddr, 50);
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            a = getch();
            if (a == 'y' || a == 'Y')
            {
                strcpy(address, taddr);
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
            cout << "\n\t\t\t\tEnter the new age :";
            cin >> tage;
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            a = getch();
            if (a == 'y' || a == 'Y')
            {
                age = tage;
                flag = 1;
                break;
            }
        }
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
    int c;
    char r;
    bool vari = 0;
    menu();
    cin >> c;
    switch (c)
    {
    case 1:
    {
    start:
        int AdmOpt;
        Firstmenu();
        cin >> AdmOpt;
        switch (AdmOpt)
        {
        case 1:
            bool s;
            cout << "\n\t\t\t\t"
                 << "Login page";
            s = loginsystem();
            if (s = true)
            {
                main();
            }
            else
                break;

        case 2:
            Register();
            cout << "\t\t\t\t"
                 << "Press m or M to goto mainmenu: ";
            cin >> r;
            if (r == 'm' || r == 'M')
            {
                main();
            }
            else
                break;
        default:
        {
            cout << "\t\t\t\t"
                 << "Wrong Entry try again!!";
            goto start;
        }
        }
        break;
    }
    case 2:
    {
        cout << "\n\t\t\t\tUser section:";
        usersection();
        cout << "\n\t\t\t\tPress m or M to goto mainmenu: ";
        cin >> r;
        if (r == 'm' || r == 'M')
        {
            main();
        }
        else
            break;
    }
    case 3:
    {
        cout << "\t\t\t\t"
             << "We are exiting.!! Thank you.";
        exit(0);
    }
    default:
        cout << "\t\t\t\t"
             << "Wrong Entry try again!!";
        main();
    }

    return 0;
}

void menu()
{
    cout << "\n \n \n \n";
    system("cls");
    headanimation();
    std::cout << "                         ************************************************************\n";
    std::cout << "                         *                                                          *\n";
    std::cout << "                         *                       Main Menu                          *\n";
    std::cout << "                         *                                                          *\n";
    std::cout << "                         *    1. Admin                                              *\n";
    std::cout << "                         *    2. User                                               *\n";
    std::cout << "                         *    3. Exit                                               *\n";
    std::cout << "                         *                                                          *\n";
    std::cout << "                         *                                                          *\n";
    std::cout << "                         ************************************************************\n";
    std::cout << "\n                                 Enter the option to go to the respective section:";
}
void Firstmenu()
{
    system("cls");
    headanimation();
    //cout << "\n \n";
    //cout << "\t\t\t\t"<< "1st menu\n";
    std::cout << "                         ************************************************************\n";
    std::cout << "                         *                          Admin 1st Menu                  *\n";
    std::cout << "                         *    1. Login                                              *\n";
    std::cout << "                         *    2. Register                                           *\n";
    std::cout << "                         *                                                          *\n";
    std::cout << "                         ************************************************************\n";
    std::cout << "\n                        Enter the option to perform respective action: ";
}
void Admsecondmenu()
{
    system("cls");
    headanimation();
    std::cout << "                         ***********************************************************\n";
    std::cout << "                         *                                                         *\n";
    std::cout << "                         *             Admin 2nd menu                              *\n";
    std::cout << "                         *                                                         *\n";
    std::cout << "                         *    1. Report                                            *\n";
    std::cout << "                         *    2. Room management                                   *\n";
    std::cout << "                         *    3. User detail modification                          *\n";
    std::cout << "                         *    4. Main menu                                         *\n";
    std::cout << "                         *    5. Exit                                              *\n";  
    std::cout << "                         *                                                         *\n";
    std::cout << "                         *                                                         *\n";
    std::cout << "                         ***********************************************************\n";
    std::cout << "\n                          Enter the option to go to the respective section: ";
}
void UserDetailModiMenu()
{
    system("cls");
    headanimation();
    std::cout << "                        ************************************************************\n";
    std::cout << "                        *                                                          *" << std::endl;
    std::cout << "                        *         Admin side user control                          *" << std::endl;
    std::cout << "                        *                                                          *" << std::endl;
    std::cout << "                        *  1. Check-in                                             *" << std::endl;
    std::cout << "                        *  2. Check-out                                            *" << std::endl;
    std::cout << "                        *  3. Edit-User Data                                       *" << std::endl;
    std::cout << "                        *                                                          *" << std::endl;
    std::cout << "                        ************************************************************" << std::endl;
    std::cout << "\n                        Enter the option to perform respective action: ";
}
void roommanagement()
{

    int choice, s; // bool breaker;
    int roomid;
    while (true)
    {
        system("cls");
        headanimation();
        //cout << "\t\t\t\t"<< "3rd memu\n";
        std::cout << "                     ***********************************************************" << std::endl;
        std::cout << "                     *                 ROOM MANAGEMENT SYSTEM                  *\n";
        std::cout << "                     *  1. Add Room                                            *\n";
        std::cout << "                     *  2. Edit Room                                           *\n";
        std::cout << "                     *  3. Delete Room                                         *\n";
        std::cout << "                     *  4. Display all room                                    *\n";
        std::cout << "                     *  5. Goto main menu                                      *\n";
        std::cout << "                     *  6. exit                                                *\n";
        std::cout << "                     *                                                         *\n";
        std::cout << "                     ***********************************************************\n";
        std::cout << "                      Enter the option to perform the respective action: ";
        cin >> choice;

        cin.ignore(); // Clear the newline character left in the buffer
        switch (choice)
        {
        case 1:
        {
            Room Room1;

            s = Room1.input();
            if (s == 2)
            {
                ofstream outputFile("Room.txt", ios::binary | ios::app | ios::out);
                if (!outputFile.is_open())
                {
                    cout << "Error opening file for writing!" << endl;
                    exit(0);
                }
                outputFile.write(reinterpret_cast<const char *>(&Room1), sizeof(Room));
                outputFile.close();
                cout << "\t\t\t\tRoom data added successfully." << endl;
                smile();
                getch();
                break;
            }
            else if (s == 1)
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
            displayTable();
            cout << "\n\t\t\t\tDelete room ";
            cout << "\n\t\t\t\tEnter the room id: ";
            roomid = intvalidater();
            deleteroom(roomid);
            break;
        }
        case 4:
        {
            system("cls");
            cout << "\n\n\n\n\t\t\tThese are all the room\n";
            cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
            cout << "| S.N|    Room code |        Room type     |   Price   | Discount | VAT   |" << endl;
            cout << "+----+-------------+-----------------------+-----------+----------+-------+" << endl;
            ifstream inputFile("Room.txt", ios::binary | ios::in);
            if (!inputFile.is_open())
            {
                cout << "Error opening file for reading!" << endl;
                exit(0);
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
            getch();
            break;
        }
        case 5:
        {
            return;
        }

        case 6:
        {
            cout << "\t\t\t\tExiting program." << endl;
            exit(0);
        }
        default:
            cout << "\t\t\t\tInvalid choice. Please select again." << endl;
        }
    }
}
void usersection()
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
            cout << "\n\n\t\t\t\t User checked-out successfull !!" << endl;
            cout << "\n\t\t\t\t Thank you for the stay!! " << endl;
            cout << "\n\t\t\t\t We are exiting.";
            smile();
            exit(0);
            break;
        }
        case 3:
        {
            int t;
            cout << "\t\t\t\t"
                 << "\nMy details \n";
            cout << "\t\t\t\t"
                 << "\nEnter the roomcode:";
            cin >> t;
            ifstream inputFile("UserRecordsFile.txt", ios::binary | ios::in);
            if (!inputFile.is_open())
            {
                cout << "Error opening file for reading!" << endl;
                return;
            }
            User obj;
            while (inputFile.read((char *)&obj, sizeof(User)))
            {
                if (t == obj.roCode())
                {
                    obj.displayData();
                    inputFile.close();
                    getch();
                    break;
                }
            }
            inputFile.close();
            getch();
            break;
        }

        case 4:
        {
            return;
        }
        case 5:
        {
            // cout << "\nYetikae dummy case banayeko maile";
            exit(0);
            break;
        }
        // case 6:
        // {
        //     system("cls");
        //     ifstream inputFile("UserRecordsFile.txt", ios::binary | ios::in);
        //     if (!inputFile.is_open())
        //     {
        //         cout << "Error opening file for reading!" << endl;
        //         exit(0);
        //     }
        //     User obj;
        //     while (inputFile.read((char *)&obj, sizeof(User)))
        //     {
        //         obj.displayData();
        //     }
        //     inputFile.close();
        //     getch();
        //     break;
        // }
            // case 5:
            // {
            //     system("cls");
            //     int r;
            //     cout << "Enter the roomcode";
            //     cin >> r;
            //     deleteUserdata(r);
            //     break;
            // }

        default:
            cout << "\nPlease try again";
            break;
        }
    }
}

int login()
{
    string userID, userpw, uID, Upass;
    int count;
    cout << "\n\n\n\n\t\t\t\tEnter your username: ";
    cin >> userID;
    cout << "\n\t\t\t\tEnter your Password: ";
    cin >> userpw;

    ifstream infile("records.txt");
    while (infile >> uID >> Upass)
    {

        if (userID == uID)
        {
            cout << "\n\t\t\t\tUsername matched ### " << endl;
            if (userpw == Upass)
            {
                cout << "\n\t\t\t\tpassword matched ####" << endl;
                count = 1;
            }
        }
    }
    infile.close();
    if (count == 1)
    {
        cout << "\n\t\t\t\tYou have logged in  successfully.\n\t\t\t\tYou can now proceed further." << endl;
        getch();
        return count;
    }
}

bool loginsystem()
{
    if (login() == 1)
    {
        int opt;
        char r;
        // cout << "Admin 2nd page menu";
        Admsecondmenu();
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            cout << "\n\t\t\t\tReport section:";
            cout << "\t\t\t\t"
                 << "\nNull, work on the progress...........";
            cout << "\t\t\t\t"
                 << "Press m or M to goto mainmenu";
            cin >> r;
            if (r == 'm' || r == 'M')
            {
                return true;
            }
            else
                break;
        }
        case 2:
        {
            cout << "\n\t\t\t\tRoom management menu: ";
            roommanagement();
            cout << "\t\t\t\t"
                 << "Press m or M to goto mainmenu";
            cin >> r;
            if (r == 'm' || r == 'M')
            {
                return true;
            }
            else
                break;
        }
        case 3:
        {
            cout << "\n\t\t\t\tUser detail modicfication";
            UserDetailModifManagement();
            cout << "\n"
                 << "\t\t\t\tNull, work on the progress...........";
            cout << "\n\t\t\t\t"
                 << "Press m or M to goto mainmenu";
            cin >> r;
            if (r == 'm' || r == 'M')
            {
                cout<<"j";
                c
                return true;
            }
            else
                break;
        }
        case 4:
        {
            return true;
            break;
        }
        case 5:
        {
            cout<<"\nWe are exiting...";
            exit(0);
        }
        default:
            cout << "\n\t\t\t\t"
                 << "Wrong Entry try again!!";
        }
    }
    else
        return false;
}
void Register()
{
    string userID, userpw;
    cout << "\n\n\n\n\n\t\t\t\tFor Registration ";
    cout << "\n\t\t\t\tEnter your username:";
    cin >> userID;
    cout << "\t\t\t\tEnter your Password:";
    cin >> userpw;

    ofstream outfile("records.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << userID << " " << userpw << endl;
        outfile.close();
        cout << "\n\t\t\t\tRegistration successfull";
    }
    else
    {
        cout << "Couldn't open file";
    }
    // main();
}

// Smile animation....
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
        if (flag = 0)
        {
            cout << "\t\t\t\tRoom doesn't exist";
            cin.get();
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
    cout << "\n\t\t\t\t------------Room deleted successfully------------" << endl;
    smile();
    getch();
}
// yaha samma ho room management lae chahine function

// Yaha dekhi muni sab user section lae use hune function haru hunxa
void usermenu()
{
    system("cls");
    headanimation();
    //cout << "\n \n \n \n";
    std::cout << "                         *****************************************************" << std::endl;
    std::cout << "                         *                                                   *" << std::endl;
    std::cout << "                         *                 USER SECTION                      *" << std::endl;
    std::cout << "                         *                                                   *" << std::endl;
    std::cout << "                         *  1. Check-In                                      *" << std::endl;
    std::cout << "                         *  2. Check-out                                     *" << std::endl;
    std::cout << "                         *  3. My details                                    *" << std::endl;
    std::cout << "                         *  4. Goto main menu                                *" << std::endl;
    std::cout << "                         *  5. Exit                                          *" << std::endl;
    // std::cout << "                         *  6. Display all user details                      *" << std::endl;
    std::cout << "                         *                                                   *" << std::endl;
    std::cout << "                         *****************************************************" << std::endl;
    std::cout << "\n                          Enter the number to choose the option : ";
}

void check_in()
{
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
    int RoCode, lamount, pay, lmoney = 0, totalprice;
    int tempprice;
    float tempdis, tempvat;
    char temprotype[50];
    char tempGname[50], tempAddress[50];
    cout << "\t\t\t\t"
         << "Enter the roomcode: ";
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
    //    cout << "yaha";

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

    cout << "\n\n\t\t\t\tPlease enter amount to be paid here: ";
    cin >> pay;
    // This lable is to recheck whether the amount is fully paid after left money is added
check:
    pay += lmoney;
    lamount = pay - totalprice;
    if (lamount < 0)
    {
        cout << "\n\t\t\t\tNot enough amount !! " << endl;
        cout << "\t\t\t\tThe remaning money to pay: " << lamount << endl;
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
    cin.ignore();
    //     exit(0);
}
int totalamount(int price, int days)
{

    return (price * days);
}

void deleteUserdata(int n)
{
    User del, hh;
    int flag = 0;
    ifstream infile("UserRecordsFile.txt", ios::binary);
    ofstream outfile("tmp.txt", ios::binary);
    if (!infile)
    {
        cout << "\n\t\t\t\tRoom.txt is not opening" << endl;
        cin.get();
        return;
    }
    else if (!outfile)
    {
        cout << "\n\t\t\t\ttmp.txt is not opening";
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
            cout << "\n\t\t\t\tUser doesn't exist";
            cin.get();
            return;
        }
    }
    outfile.close();
    infile.close();
    remove("UserRecordsFile.txt");
    rename("tmp.txt", "UserRecordsFile.txt");
    closeandopenforuserfile();

    smile();
    // getch();
}
void roomAllocandDealloc(int n, int sw)
{
    Room st, tmp;
    int rid = n, flag = 0, fpos = -1;
    fstream file;
    file.open("Room.txt", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "\t\t\t\tError opening file for editing !";
        return;
    }
    else
    {
        while (file.read((char *)&st, sizeof(Room)))
        {
            if (rid == st.rocode())
            {
                cout << "\n\t\t\t\tRoom found";
                flag = 1;
                fpos = (int)file.tellg();
                break;
            }
        }
        if (flag == 0)
        {
            cout << "\t\t\t\tRoom doesn't exist for allocation";
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

void UserDetailModifManagement()
{
    system("cls");
    int choice;

    while (true)
    {
        UserDetailModiMenu();
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
            cout << "\n\n\t\t\t\t User checked-out successfull !!" << endl;
            cout << "\n\t\t\t\t Thank you for the stay!! " << endl;
            cout << "\n\t\t\t\t We are exiting.";
            smile();
            exit(0);
            break;
        }
        case 3:
        {
            system("cls");
            int r;
            cout << "\n\t\t\t\tEdit page" << endl;
            cout << "\n\t\t\t\tEnter the roomcode: ";
            cin >> r;
            editUserdata(r);
            break;
        }
        default:
            cout << "Please!! Try again.";
            system("pause");
        }
    }
}

void editUserdata(int n)
{
    User tmp, st;
    int rid = n, flag = 0, fpos = -1;
    fstream file;
    file.open("UserrecordsFile.txt", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "Error opening file for editing !";
        return;
    }
    else
    {
        while (file.read((char *)&st, sizeof(User)))
        {
            if (rid == st.roCode())
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
        file.seekp(fpos - sizeof(User), ios::beg);
        tmp = st;
        tmp.actualeditUser(rid);

        file.write((char *)&tmp, sizeof(User));
        file.close();
        getch();
    }
}

void headanimation()
{
    const char statement[]={"Hotel Room Booking and Management System"};
    int length=sizeof(statement)-1;
    cout<<"\n\t\t\t\t   ";
   for (int i = 0; i < length; ++i) {
        std::cout << statement[i] << std::flush;
        Sleep(100); // 2000 milliseconds = 2 seconds
    }
    cout<<"\n\n";
}