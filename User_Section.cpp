#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <cmath>
#include <windows.h>
#include <iomanip>
using namespace std;
int totalamount(int, int);
void smile();
void deleteUserdata(int);
void deleteroom(int);
void againopenandclosefile();
void roomAllocandDealloc(int, int);
// Room class
class Room
{
public:
    char roomtype[50];
    int rcode;
    bool flag;
    int price;
    float discount;
    float VAT;
    void input()
    {
        flag = false;
        int choice, n;
        cout << "Enter Room type: ";
        cin.getline(roomtype, 50);
        cout << "Enter Room  code: ";
        cin >> rcode;
        cout << "Enter Room price: ";
        cin >> price;
        cout << "Enter Discount percentage: ";
        cin >> discount;
        cout << "Enter VAT percentage: ";
        cin >> VAT;
        // cout << "\nDo you want to add additional feature of this rooom";
        // cout << "\nIf yes enter 1 else any other key ";
        // cin >> choice;
        // if (choice == 1)
        // {
        //     cout << "Enter the total number of feature:";
        //     cin >> n;
        //     EntSpF(n);
        // }
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

// User class
class User
{
private:
    int roomCode;
    char name[50];
    char address[50];
    int age;

public:
    // Constructor to initialize the object
    User()
    {
        roomCode = 0;
        // name = "";
        // address = "";
        age = 0;
    }

    // Member function to take input for data members
    void inputData()
    {
        char c;
    repeat:
        cout << "\nEnter Room Code: ";
        cin >> roomCode;

        cout << "Enter Name: ";
        cin.ignore(); // Ignore any previous newline character
        cin.getline(name, 50);

        cout << "Enter Address: ";
        cin.getline(address, 50);

        cout << "Enter Age: ";
        cin >> age;
        cout << "\nPlease review your data and enter 'Y' or 'y'  to confirm it: ";
        cin >> c;
        if (c == 'Y' || c == 'y')
        {
            if (age < 18)
            {
                cout << "\nAge is invalid!! \n Re-enter the age: ";
                cin >> age;
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

void usermenu()
{
    cout << "\n1.Check-in";
    cout << "\n2.Check-out";
    cout << "\n3.Exit";
    cout << "\n4. Display the data in the file";
    cout << "\n5.Delete the data";
    cout << "\n\nEnter your choice: ";
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
    int RoCode, lamount, pay, lmoney = 0,totalprice;
    int tempprice;
    float tempdis,tempvat;
    char temprotype[50];
    char tempGname[50], tempAddress[50];
    cout << "Enter the roomcode: ";
    cin >> RoCode;
    Room tobj;    // tobj=Temporary object
    User dispobj; // dispobj=object being used for the display
    ifstream infile("Room.txt", ios::binary | ios::in);
    ifstream infile1("UserRecordsFile.txt", ios::binary | ios::in);
    if (!infile.is_open())
    {
        cout << "Opening of room file is not successfull.";
        return;
    }
    else if (!infile1.is_open())
    {
        cout << "Opening of userfile is not successfull.";
        return;
    }

    //reading from the roomfile and getting the desired data is done here
    while (infile.read((char *)&tobj, sizeof(Room)))
    {
        if (RoCode == tobj.rocode())
        {
            cout << "\nRoom file ma room vetiyo";
            tempprice = tobj.retPrice();
            tempdis=tobj.retDiscount();
            tempvat=tobj.retVat();
            strcpy(temprotype, tobj.retRoomtype());
        }
    }
    //reading from the userfile and getting the desired data is done here
    while (infile1.read((char *)&dispobj, sizeof(User)))
    {
        if (RoCode == dispobj.roCode())
        {
            cout << "\nUser ko ma pani room vetiyo";
            strcpy(tempGname, dispobj.retName());
            strcpy(tempAddress, dispobj.retAddress());
        }
    }
    infile.close();
    infile1.close();
    cout << "\nGuest name: " << tempGname;
    cout << "\nAddress: " << tempAddress;
    cout << "\nRoom type: " << temprotype;
    cout << "\nprice: " << tempprice;
    
    // calculation part
    // 1st parameter =price and 2nd paramter=total days stayed here 4 is dummy value
    totalprice=totalamount(tempprice, 4);
    totalprice=totalprice+(totalprice*(tempvat/100))-(totalprice*(tempdis/100));
    cout << "\nTotal amount: " << totalprice;
    
    cout << "\nPlease enter amount to be paid here: ";
    cin >> pay;
// This lable is to recheck whether the amount is fully paid after left money is added
check:
    pay += lmoney;
    lamount = pay - totalprice;
    if (lamount < 0)
    {
        cout << "The paid money is not enough ";
        cout << "please enter the left money :" << lamount;
        cin >> lmoney;
        goto check;
    }
    else if (lamount > 0)
    {
        cout << "Your return amount is:" << lamount;
    }
    deleteUserdata(RoCode);
    roomAllocandDealloc(RoCode, 0);
}

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
            check_in();
            cout << "\nValid age and user checked-in successfull.";
            getch();
            break;
        }
        break;
        case 2:
        {
            check_out();
            cout << "\n------- -----User checked-out successfully------------";
            cout << "\nThank you for the stay!! ";
            cout << "\nWe are exiting.";
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

// Function to calculate total money of the bill
int totalamount(int price, int days)
{

    return (price * days);
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
        cout << "Error opening file for editing !";
        return;
    }
    else
    {
        while (file.read((char *)&st, sizeof(Room)))
        {
            if (rid == st.rcode)
            {
                cout << "\nRoom found";
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
// File that we are creating is UserRecordsFile.txt