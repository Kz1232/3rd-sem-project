#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Room
{
public:
    char roomtype[50];
    int rcode;
    int price;
    int discount;
    int VAT;
    void input()
    {
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
    }
    void actualedit(int);
    void display()
    {
        cout << "Room code: " << rcode << endl;
        cout << "Room type: " << roomtype << endl;
        cout << "Price: " << price << endl;
    }
};
void Room::actualedit(int n)
{
    char rtype[20], g;
    cout << "Room id:" << n << endl;
    cout << "Room type:" << roomtype << endl;
    cout << "Enter 'a' to change the room type:";
    cin >> g;
    if (g == 'a')
    {
        cout << "Enter the new room type:";
        cin >> rtype;
        strcpy(roomtype, rtype);
        cout << "\nThe room name modified successfull" << endl;
        cin.get();
        return;
    }
    else
    {
        cout << "Can't perform the operation";
        return;
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
        // tmp.actualedit(st.roomtype,rid,st.price);
        tmp.actualedit(rid);

        file.write((char *)&tmp, sizeof(Room));
        file.close();
    }
}
// sometime files doesnt respond so opening and closing is done to make sure that.
void againopenandclosefile()
{
      ifstream inFile;
      Room aa;
      inFile.open("room.txt", ios::binary);
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
    Room del, hh; int flag=0;
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
        infile.seekg(0,ios::beg);
        while (infile.read((char *)&hh, sizeof(Room)))
        {
            if (n == hh.rcode) // Checking the existence of room
            {
                cout << "room exist;";
                flag=1;
                infile.seekg(0,ios::beg);
                //Writing of content in temp file starts here
                // logic used: Writing all the content except deleting content in temp file and renaming the temp file to original file.
                 while (infile.read((char *)&del, sizeof(Room)))
                {
                    if (n != del.rcode)
                    {
                        outfile.write((char *)&del, sizeof(Room));
                    }
                }
            }
        }
        if(flag==0)
        {
            cout<<"Room doesn't exist";
            cin.get();
            return;
        }
    }
    outfile.close();
    infile.close();
    remove("Room.txt");
    rename("tmp.txt","Room.txt");
    againopenandclosefile();
    cout<<"\n------------Room deleted successfully------------"<<endl;
    cout<<"Hurreh 😃 "<<endl;

}
int main()
{
    int choice;
    int roomid;
    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Add Room \n";
        cout << "2.Edit Room \n";
        cout << "3.Display Room data\n";
        cout<<  "4.Delete Room \n";
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
            break;
        }
        case 4:
        {
                cout<<"Enter the room id";
                cin>>roomid;
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
    }

    return 0;
}
/*  Output of the program:
Menu:
1. Add Room        
2.Edit Room        
3.Display Room data
4.Delete Room      
5. Exit
Enter your choice: 1
Enter Room type: Deluxe
Enter Room  code: 11
Enter Room price: 2300
Enter Discount percentage: 0
Enter VAT percentage: 0
Room data added successfully.
Menu:
1. Add Room 
2.Edit Room
3.Display Room data
4.Delete Room
5. Exit
Enter your choice: 3
Room code: 11
Room type: Deluxe
Price: 2300
Menu:
1. Add Room
2.Edit Room 
3.Display Room data
4.Delete Room
5. Exit
Enter your choice: 2
Enter the room id:11
Room id:11
Room type:Deluxe
Enter 'a' to change the room type:a
Enter the new room type:Simple

The room name modified successfull
Menu:
1. Add Room
2.Edit Room
3.Display Room data
4.Delete Room
5. Exit
Enter your choice: 3
Room code: 11
Room type: Simple
Price: 2300
Menu:
1. Add Room
2.Edit Room
3.Display Room data
4.Delete Room 
5. Exit
Enter your choice: 1
Enter Room type: Smart 
Enter Room  code: 200
Enter Room price: 4000
Enter Discount percentage: 0  
Enter VAT percentage: 12
Room data added successfully.
Menu:
1. Add Room
2.Edit Room 
3.Display Room data
4.Delete Room
5. Exit
Enter your choice: 3
Room code: 11
Room type: Simple
Price: 2300
Room code: 200
Room type: Smart
Price: 4000
Menu:
1. Add Room
2.Edit Room
3.Display Room data
4.Delete Room
5. Exit
Enter your choice: 4
Enter the room id200
room exist;
------------Room deleted successfully------------
Hurreh ≡ƒÿâ
Menu:
1. Add Room
2.Edit Room
3.Display Room data
4.Delete Room 
5. Exit
Enter your choice: 5
Exiting program.
*/