#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <cmath>
#include <windows.h>
using namespace std;
int totalamount(int, int);
void smile();
void deleteUserdata(int);
void deleteroom(int);
void againopenandclosefile();
void roomAllocandDealloc(int,int);
// Room class
class Room
{
public:
    char roomtype[50];
    int rcode;
    int price;
    bool flag;
    int discount;
    int VAT;
    string special_feature[20];
    void EntSpF(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter the name of feature " << i + 1 << ": ";
            getline(cin, special_feature[i]);
        }
    }
    void input()
    {   flag=0;
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
        cout << "\nDo you want to add additional feature of this rooom";
        cout << "\nIf yes enter 1 else any other key ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the total number of feature:";
            cin >> n;
            EntSpF(n);
        }
    }
    void actualedit(int);
    void display()
    {
        cout << "Room code: " << rcode << endl;
        cout << "Room type: " << roomtype << endl;
        cout << "Price: " << price << endl;
    }
    int rocode()
    {
        return rcode;
    }
    int retDiscount()
    {
        return discount;
    }
    int retPrice()
    {
        return price;
    }
    int retVat()
    {
        return VAT;
    }
    char *retRoomtype()
    {
        return roomtype;
    }
    string *retSpecial_feature()
    {
        return special_feature;
    }
    void flagon()
    {
        flag=true;
    }
    void flagoff()
    {
        flag=false;
    }
};

// User class
class User
{
private:
    int roomCode;
    string name;
    string address;
    int age;

public:
    // Constructor to initialize the object
    User()
    {
        roomCode = 0;
        name = "";
        address = "";
        age = 0;
    }

    // Member function to take input for data members
    void inputData()
    {
        char c; Room temp;
        repeat:
        cout << "Enter Room Code: ";
        cin >> roomCode;

        cout << "Enter Name: ";
        cin.ignore(); // Ignore any previous newline character
        getline(cin, name);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Age: ";
        cin >> age;
        cout << "\nPlease review your data and enter 'Y' or 'y'  to confirm it";
        cin>>c;
        if (c == 'Y' || c == 'y')
        {
            if (age < 18)
            {
                cout << "\nAge is invalid!! \n Re-enter the age: ";
                cin >> age;
            }
           roomAllocandDealloc(roomCode,1); 
            cout << "\nValid age and user checked-in successfull";
        }
        else
            goto repeat;
    }

    // Member function to display user information
    void displayData()
    {
        cout << "Room Code: " << roomCode << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
    }
    string retName()
    {
        return name;
    }
    string retAddress()
    {
        return address;
    }
    int rocode()
    {
        return roomCode;
    }
};

void usermenu()
{
    cout << "\n1.Check-in";
    cout << "\n2.Check-out";
    cout << "\n3.Exit";
    cout << "\nEnter your choice: ";
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
                return ;
            }
             writeFile.write(reinterpret_cast<const char *>(&user1), sizeof(User));
            writeFile.close();
}

void check_out()
{
    int RoCode, tempprice, lamount, pay, lmoney = 0;
    char *temprotype;
    string tempGname, tempAddress;
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
    cout << "yaha";

    while (infile.read((char *)&tobj, sizeof(Room)))
    {
        cout << "\n1";
        if (RoCode == tobj.rocode())
        {
            tempprice = tobj.retPrice();
            temprotype = tobj.retRoomtype();
        }
    }
    while (infile1.read((char *)&dispobj, sizeof(User)))
    {
        cout << "\n2";
        if (RoCode == dispobj.rocode())
        {
            tempGname = dispobj.retName();
            tempAddress = dispobj.retAddress();
        }
    }
    infile.close();
    infile1.close();
    cout << "\nGuest name: " << tempGname;
    cout << "\nAddress: " << tempAddress;
    cout << "\nRoom type: " << temprotype;
    cout << "\nprice: " << tempprice;
    // 1st parameter =price and 2nd paramter=total days stayed here 4 is dummy value
    cout << "\nTotal amount: " << totalamount(tempprice, 4);

    // // File is read and each object values stored in the files is checked in below while statement two files are read
    // while(infile.read((char *)&tobj,sizeof(Room)))
    // { cout<<"\n1";
    //     if(RoCode==tobj.rocode())
    //     {
    //         cout<<"\n2";
    //     while(infile1.read((char*)&dispobj,sizeof(User)))
    //     {
    //         cout<<"\n3";

    //         if(RoCode==dispobj.rocode())
    //     { cout<<"\n 4";
    //            tempprice=tobj.retPrice();
    //         cout<<"\nGuest name: "<<dispobj.retName();
    //         cout<<"\nAddress: "<<dispobj.retAddress();
    //         cout<<"\nRoom type: "<<tobj.retRoomtype();
    //         cout<<"\nprice: "<<tempprice;

    //         // 1st parameter =price and 2nd paramter=total days stayed here 4 is dummy value
    //         cout<<"\nTotal amount: "<<totalamount(tempprice,4);
    //             break;
    //             }
    //         }
    //      infile1.clear();
    //      infile1.seekg(0);
    //     }

    // }
    // infile1.close();
    // infile.close();
    cout << "\nPlease enter amount to be paid here: ";
    cin >> pay;
// This lable is to recheck whether the amount is fully paid after left money is added
check:
    pay += lmoney;
    lamount = pay - tempprice;
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
        deleteUserdata(RoCode);
    }

    else
    {
        deleteUserdata(RoCode);
        cout << "Thank you for the stay!! ";
        cout << "We are exiting.";
        smile();
        exit(0);
    }
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
            getch();
            break;
        }
        break;
        case 2:
            check_out();
            cout << "\n------- -----User checked-out successfully------------" << endl;
            break;
        case 3:
            cout << "\nYetikae dummy case banayeko maile";
            exit(0);
            break;

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

void smile()
{
    cout<<"\n";
    cout << "  *****" << endl;
    cout << " *     *" << endl;
    cout << "*  O O  *" << endl;
    cout << "*   ^   *" << endl;
    cout << " * \\_/ *" << endl;
    cout << "  *****" << endl;
}
/*
void deleteroom(int n)
{
    Room del, hh;
    int flag = 0;
    ifstream infile("Room.txt", ios::binary);
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
        while (infile.read((char *)&hh, sizeof(Room)))
        {
            if (n == hh.rcode) // Checking the existence of room
            {
                cout << "room exist;";
                flag = 1;
                infile.seekg(0, ios::beg);
                // Writing of content in temp file starts here
                //  logic used: Writing all the content except deleting content in temp file and renaming the temp file to original file.
                while (infile.read((char *)&del, sizeof(Room)))
                {
                    if (n != del.rcode)
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
            return;
        }
    }
    outfile.close();
    infile.close();
    remove("Room.txt");
    rename("tmp.txt", "Room.txt");
    againopenandclosefile();
    cout << "\n------------Room deleted successfully------------" << endl;
    smile();
    getch();
}*/
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
            if (n == hh.rocode()) // Checking the existence of room
            {
                cout << "User exist;";
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
            cout << "User doesn't exist";
            cin.get();
            return;
        }
    }
    outfile.close();
    infile.close();
    remove("Room.txt");
    rename("tmp.txt", "Room.txt");
    againopenandclosefile();

    smile();
    getch();
}


void roomAllocandDealloc(int n,int sw )
{
    Room st,tmp;
    cout<<"We are inside the function";
    int rid=n, flag=0, fpos=-1;
    fstream file;
     file.open("Room.txt", ios::binary | ios::in | ios::out);
     if (!file)
    {
        cout << "Error opening file for editing !";
        return;
    }
    else
    { 
        cout<<"\nwe are inside the else statement";
        while (file.read((char *)&st, sizeof(Room)))
        {
            if (rid == st.rcode)
            { cout<<"\nRoom found";
                flag = 1;
                fpos = (int)file.tellg();
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Room doesn't exist";
            cin.get();
            return;
        }
       file.seekp(fpos - sizeof(Room), ios::beg);
        tmp=st;
        if(sw == 1)
        {
            cout<<"\nFlag on vayo";
        tmp.flagon();
        }
        else{
        tmp.flagoff();
       }
      
       
      
        cout<<"\nFile write ma problem aayo tara banyo";
        file.write((char *)&tmp,sizeof(Room));
        cout<<"\n file write vayo";
        file.close();
        cout<<"\n file close vayo";
    }
}
// File that we are creating is UserRecordsFile.txt