#include <iostream>
#include<conio.h>
#include<fstream>
#include <cstring>
#include <stdlib.h>
#include<iomanip>
using namespace std;
void menu();      
void Firstmenu();
void secondmenu();
void usermenu();
void UserDetailModi();
void roommanagement();
void usersection();
int login();
bool loginsystem();
void Register();
void smile();
void edit(int);
void againopenandclose();
void deleteroom(int);
void check_in();
void check_out();
int totalamount(int,int);
void deleteUserdata(int);
void roomAllocandDealloc(int,int);
void closeandopenforuserfile();
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
        cout << "\t\t\t\tEnter Room  code: ";
        cin >> rcode;
        cout << "\t\t\t\tEnter Room price: ";
        cin >> price;
        cout << "\t\t\t\tEnter Discount percentage: ";
        cin >> discount;
        cout << "\t\t\t\tEnter VAT percentage: ";
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
        cout <<"\t\t\t\t|   "<<setw(5)<<rcode<<"     |   "<<setw(12)<<roomtype<<"        |  "<<setw(6)<<price<<"  |   "<<setw(5)<<discount<<"    | "<<setw(5)<<VAT<<"|" << endl;
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
        cout<<"\n\t\t\t\tEnter Room Code: ";
        cin >> roomCode;

        cout << "\t\t\t\tEnter Name: ";
        cin.ignore(); // Ignore any previous newline character
        cin.getline(name, 50);

        cout<<"\t\t\t\t" << "Enter Address: ";
        cin.getline(address, 50);

        cout<<"\t\t\t\t" << "Enter Age: ";
        cin >> age;
        cout<<"\t\t\t\t" << "\nPlease review your data and enter 'Y' or 'y'  to confirm it: ";
        cin >> c;
        if (c == 'Y' || c == 'y')
        {
            if (age < 18)
            {
                cout<<"\n\t\t\t\tAge is invalid!!"; 
                cout<<"\n\t\t\t\t Re-enter the age: ";
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
        cout<<"\n\t\t\t\t" << "Room Code: " << roomCode << endl;
        cout<<"\t\t\t\t" << "Name: " << name << endl;
        cout<<"\t\t\t\t" << "Address: " << address << endl;
        cout<<"\t\t\t\t" << "Age: " << age << endl;
        cout<<"\t\t\t\t" << "\n";
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
            cout<<"\n\t\t\t\t" << "Login page";
            s=loginsystem();
            if(s=true)
            {
                main();
            }
            else break;
                break;
        case 2:
            Register();
            cout<<"\t\t\t\t" << "Press m or M to goto mainmenu: ";
            cin >> r;
            if (r == 'm' || r == 'M')
            {
                main();
            }
            else
                break;
        default :
            {
                cout<<"\t\t\t\t" << "Wrong Entry try again!!";
                goto start;
            }
        }
        break;
    }    
    case 2:
    {
        cout<<"\n\t\t\t\tUser section:";  
        usersection();
        cout<<"\n\t\t\t\tPress m or M to goto mainmenu: ";
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
        cout<<"\t\t\t\t" << "We are exiting.!! Thank you.";
        exit(0);
    }
    default:
        cout<<"\t\t\t\t" << "Wrong Entry try again!!";
        main();
    }

    return 0;
}

void menu()
{   cout<<"\n \n \n \n";
   system("cls");
    cout<<"\n\t\t\t\t"<<"Main Menu \n";
    	std::cout <<"                            ***********************************************************\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *             Hotel Room Booking and Management System    *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *    1. Admin                                             *\n";
        std::cout << "                            *    2. User                                              *\n";
        std::cout << "                            *    3. Exit                                              *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            ***********************************************************\n";
        std::cout << "\n                                 Enter the option to go to the respective section:";
}
void Firstmenu()
{   cout<<"\n \n \n \n";
    cout<<"\t\t\t\t"<<"1st menu\n";
        std::cout << "                   *******************************************************************\n";
        std::cout << "                   *                          Admin 1st Menu                         *\n";
        std::cout << "                   *    1. Login                                                     *\n";
        std::cout << "                   *    2. Register                                                  *\n";
        std::cout << "                   *                                                                 *\n";
        std::cout << "                   *******************************************************************\n";
        std::cout << "\n                        Enter the option to perform respective action:";
}
void secondmenu()
{   cout<<"\n \n \n \n";
        std::cout << "                            ***********************************************************\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *             2nd menu                                    *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *    1. Report                                            *\n";
        std::cout << "                            *    2. Room management                                   *\n";
        std::cout << "                            *    3. User detail modification                          *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            ***********************************************************\n";
        std::cout << "\n                             Enter the option to go to the respective section:";      
 //getch();

}
void UserDetailModi()
{   cout<<"\n \n \n \n";
        std::cout << "                         *****************************************************" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *         USER DETAIL MODIFICATION                  *" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *  1. Check-in                                      *" << std::endl;
        std::cout << "                         *  2. Check-out                                     *" << std::endl;
        std::cout << "                         *  3. Edit-User Data                                *" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *****************************************************" << std::endl;
 getch();
}
void roommanagement()
{
   
    int choice; //bool breaker;
    int roomid;
    while (true)
    {
        system("cls");
        cout<<"\t\t\t\t"<<"3rd memu\n";
        std::cout << "                               ******************************************************\n";
        std::cout << "                               *                 ROOM MANAGEMENT SYSTEM             *\n";
        std::cout << "                               *  1. Add Room                                       *\n";
        std::cout << "                               *  2. Edit Room                                      *\n";
        std::cout << "                               *  3. Delete Room                                    *\n";
        std::cout << "                               *  4. Display all room                               *\n";
        std::cout << "                               *  5. Goto main menu                                 *\n";
        std::cout << "                               *  6. exit                                           *\n";
        std::cout << "                               *                                                    *\n";
        std::cout << "                               ******************************************************\n";
        std::cout << "                                Enter the option to perform the respective action: ";
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
                cout<<"\t\t\t\t" << "Error opening file for writing!" << endl;
                return ;
            }

            outputFile.write(reinterpret_cast<const char *>(&Room1), sizeof(Room));
            outputFile.close();
            cout<<"\t\t\t\t" << "Room data added successfully." << endl;
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
        {   cout<<"\n\n\n\n\n\t\t\t\tDelete room ";
            cout << "\n\t\t\t\tEnter the room id";
            cin >> roomid;
            deleteroom(roomid);
            break;
        }
        case 4:
        {   cout<<"\n\n\n\n\t\t\t\tThese are all the room\n";
        cout<<"\t\t\t\t" << "+-------------+-----------------------+-----------+----------+-------+" << endl;
    cout<<"\t\t\t\t" << "|    Room code |        Room type     |   Price   | Discount | VAT   |" << endl;
    cout<<"\t\t\t\t" << "+-------------+-----------------------+-----------+----------+-------+" << endl;
            ifstream inputFile("Room.txt", ios::binary);
            if (!inputFile.is_open())
            {
                cout << "Error opening file for reading!" << endl;
                return ;
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
        
        case 5:
        { 
            return;
            
        }
        case 6:
        {
            cout<<"\t\t\t\t\tExiting program." << endl;
            exit(0);

        }
        default:
            cout<<"\t\t\t\t" << "\t\t\t\tInvalid choice. Please select again." << endl;
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
            check_in();
            cout<<"\t\t\t\t" << "\nValid age and user checked-in successfull.";
            getch();
            break;
        }
        break;
        case 2:
        {
            check_out();
            //cout << "\n------- -----User checked-out successfully------------";
            cout<<"\t\t\t\t" << "\nThank you for your stay!! ";
            cout<<"\t\t\t\t" << "\nWe are exiting.";
            exit(0);
            break;
        }
          case 3:
        {
            int t;
            cout<<"\t\t\t\t"<<"\nMy details \n";
            cout<<"\t\t\t\t"<<"\nEnter the roomcode:";
            cin>>t;
             ifstream inputFile("UserRecordsFile.txt", ios::binary | ios::in);
            if (!inputFile.is_open())
            {
                cout << "Error opening file for reading!" << endl;
                return ;
            }
            User obj;
            while (inputFile.read((char *)&obj, sizeof(User)))
            {
                if(t==obj.roCode())
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

        case 6:
        {
            ifstream inputFile("UserRecordsFile.txt", ios::binary | ios::in);
            if (!inputFile.is_open())
            {
                cout << "Error opening file for reading!" << endl;
                return ;
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
            cout << "\n\t\t\t\tUsername matched" << endl;
            if (userpw == Upass)
            {
                cout << "\n\t\t\t\tpassword matched" << endl;
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
                int opt; char r;
                cout << "Admin 2nd page menu";
                secondmenu();
                cin >> opt;
                switch (opt)
                {
                case 1:
                    cout<<"\n\t\t\t\tReport section:";
                    cout<<"\t\t\t\t" << "\nNull, work on the progress...........";
                    cout<<"\t\t\t\t" << "Press m or M to goto mainmenu";
                    cin >> r;
                    if (r == 'm' || r == 'M')
                    {
                        return true;
                    }
                    else
                        break;
                case 2:
                    cout << "\n\t\t\t\tRoom management menu: ";
                    roommanagement();
                    cout<<"\t\t\t\t" << "Press m or M to goto mainmenu";
                    cin >> r;
                    if (r == 'm' || r == 'M')
                    {
                        return true;
                    }
                    else
                        break;
                case 3:
                cout<<"\n\t\t\t\tUser detail modicfication";
                UserDetailModi();
                 cout << "\n"<<"\t\t\t\tNull, work on the progress...........";
                    cout<<"\n\t\t\t\t" << "Press m or M to goto mainmenu";
                    cin >> r;
                    if (r == 'm' || r == 'M')
                    {
                        return true;
                    }
                    else
                        break;
                default :
                    cout<<"\n\t\t\t\t" << "Wrong Entry try again!!";
                }
            }
            else
            return false;
}
void Register()
{
     string userID, userpw;
    cout<<"\n\n\n\n\n\t\t\t\tFor Registration ";
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
//Yaha dekhi muniko room management lae chahine function
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
        {
            cout << "\n\t\t\t\tEnter the new room type :";
            cin >> rtype;
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            a = getch();
            if (a == 'y' || 'Y')
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
    confirm:
        cout << "\t\t\t\tEnter the new price :";
        cin >> tpri;
        cout << "\t\t\t\tPress y to confirm and n to change again: ";
        a = getch();
        if (a == 'y' || 'Y')
        {
            price = tpri;
            flag = 1;
            break;
        }
        else
        {
            goto confirm;
        }
    }
    case 3:
    {
        while (true)
        {
            cout << "\t\t\t\tEnter the new discount percentage :";
            cin >> tdis;
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            a = getch();
            if (a == 'y' || 'Y')
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
            cout << "\t\t\t\tEnter the new vat percentage :";
            cin >> tvat;
            cout << "\t\t\t\tPress y to confirm and n to change again: ";
            a = getch();
            if (a == 'y' || 'Y')
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
        cin >> c;
        if (c == 'm' || c == 'M')
        {
            goto again;
        }
    }
}
void smile()
{   cout<<"\n";
    cout <<"\t\t\t\t" << "  *****" << endl;
    cout <<"\t\t\t\t" << " *     *" << endl;
    cout <<"\t\t\t\t" << "*  O O  *" << endl;
    cout <<"\t\t\t\t" << "*   ^   *" << endl;
    cout <<"\t\t\t\t" << " * \\_/ *" << endl;
    cout <<"\t\t\t\t" << "  *****" << endl;
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
cout<<"\n \n \n \n";
        std::cout << "                         *****************************************************" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *                 USER SECTION                      *" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *  1. Check-In                                      *" << std::endl;
        std::cout << "                         *  2. Check-out                                     *" << std::endl;
        std::cout << "                         *  3. My details                                    *" << std::endl;
        std::cout << "                         *  4. Goto main menu                                *" << std::endl;
        std::cout << "                         *  5. Exit                                          *" << std::endl;
        std::cout << "                         *  6. Display all user details                      *" << std::endl;
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
    int RoCode, lamount, pay, lmoney = 0,totalprice;
    int tempprice;
    float tempdis,tempvat;
    char temprotype[50];
    char tempGname[50], tempAddress[50];
    cout<<"\t\t\t\t" << "Enter the roomcode: ";
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
//    cout << "yaha";

    while (infile.read((char *)&tobj, sizeof(Room)))
    {
        if (RoCode == tobj.rocode())
        {
            // cout << "\nRoom file ma room vetiyo";
            tempprice = tobj.retPrice();
            tempdis=tobj.retDiscount();
            tempvat=tobj.retVat();
            strcpy(temprotype, tobj.retRoomtype());
        }
    }
    while (infile1.read((char *)&dispobj, sizeof(User)))
    {
        //cout << "\n2";
        if (RoCode == dispobj.roCode())
        {
            // cout << "\nUser ko ma pani room vetiyo";
            strcpy(tempGname, dispobj.retName());
            strcpy(tempAddress, dispobj.retAddress());
        }
    }
    infile.close();
    infile1.close();
    cout <<"\n\t\t\t\tGuest name: " << tempGname;
    cout <<"\n\t\t\t\tAddress: " << tempAddress;
    cout <<"\n\t\t\t\tRoom type: " << temprotype;
    cout <<"\n\t\t\t\tprice: " << tempprice;
    
    // calculation part
    // 1st parameter =price and 2nd paramter=total days stayed here 4 is dummy value
    totalprice=totalamount(tempprice, 4);
    totalprice=totalprice+(totalprice*(tempvat/100))-(totalprice*(tempdis/100));
    cout << "\n\n\t\t\t\tTotal amount: " << totalprice;
    

    cout << "\n\n\t\t\t\tPlease enter amount to be paid here: ";
    cin >> pay;
// This lable is to recheck whether the amount is fully paid after left money is added
check:
    pay += lmoney;
    lamount = pay - totalprice;
    if (lamount < 0)
    {
        cout << "\n\t\t\t\tThe paid money is not enough ";
        cout << "\n\t\t\t\tplease enter the left money :" << lamount;
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