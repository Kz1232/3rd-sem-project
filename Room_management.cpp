#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Room
{
public:
    char roomtype[50];
    int rcode;
    bool flag;
    int price;
    int discount;
    int VAT;
    string special_feature[20];
    void EntSpF(int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<"\nEnter the name of feature "<<i+1<<": ";
            cin.ignore();
            getline(cin,special_feature[i]);
        }
    }
    void input()
    { int choice,n;
        flag=false;
        cout << "Enter Room type: ";
        cin.getline(roomtype,50);
        cout << "Enter Room  code: ";
        cin >> rcode;
        cout << "Enter Room price: ";
        cin >> price;
        cout << "Enter Discount percentage: ";
        cin >> discount;
        cout << "Enter VAT percentage: ";
        cin >> VAT;
        cout<<"\nDo you want to add additional feature of this rooom";
        cout<<"\nIf yes enter 1 else any other key ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the total number of feature:";
            cin>>n;
            EntSpF(n);
        }
    }
    void actualedit(int);
    void display()
    {
        cout << "Room code: " << rcode << endl;
        cout << "Room type: " << roomtype << endl;
        cout << "Price: " << price << endl;
        //getch();
    }
    ~Room()
    {
        cout<<"\0";
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
    int tpri, tdis, tvat;
again:
    bool flag = 0;
    cout << "  Room id:" << n << endl;
    cout << "1.Room type:" << roomtype << endl;
    cout << " 2.Price:" << price << endl;
    cout << " 3.Discount percentage " << discount << endl;
    cout << " 4.VAT percentage " << VAT << endl;
    cout << "Enter the number to change the specific option:";
    cin >> op;
    switch (op)
    {
    case 1:
    {
        while (true)
        {
            cout << "Enter the new room type :";
            cin >> rtype;
            cout << "Press y to confirm and n to change again.";
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
        cout << "Enter the new price :";
        cin >> tpri;
        cout << "Press y to confirm and n to change again.";
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
            cout << "Enter the new discount percentage :";
            cin >> tdis;
            cout << "Press y to confirm and n to change again.";
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
            cout << "Enter the new vat percentage :";
            cin >> tvat;
            cout << "Press y to confirm and n to change again.";
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
        cout << "\nEnter the 'm' or 'M' to edit more";
        cin >> c;
        if (c == 'm' || c == 'M')
        {
            goto again;
        }
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
            if (rid == st.rcode)
            {
                flag = 1;
                fpos = (int)file.tellg();
                break;
            }
        }
        if (flag = 0)
        {
            cout << "Room doesn't exist";
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
// sometime files doesnt respond so opening and closing is done to make sure that.
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
}
int main()
{
    int choice;
    int roomid;
    while (true)
    {
        system("cls");
        cout << "Menu:\n";
        cout << "1. Add Room \n";
        cout << "2.Edit Room \n";
        cout << "3.Display Room data\n";
        cout << "4.Delete Room \n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;
        cin.ignore(); // Clear the newline character left in the buffer
        switch (choice)
        {
        case 1:
        {
            Room Room1;
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

            cout << "Enter the room id:";
            cin >> roomid;
            edit(roomid);
            break;
        }
        case 3:
        {
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
        {
            cout << "Enter the room id";
            cin >> roomid;
            deleteroom(roomid);
            break;
        }
        case 5:
        {
            cout << "Exiting program." << endl;
            return 0;
        }
        default:
            cout << "Invalid choice. Please select again." << endl;
        }
        cout<<"Compiler";
    }
    return 0;
}


/* Output:-
Value of flag will determine whether it is allocated or not.





*/