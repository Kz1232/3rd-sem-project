#include <iostream>
#include<conio.h>
#include<fstream>
using namespace std;
void menu()
{   cout<<"\n \n \n \n";
   system("cls");
    cout<<"main menu \n";
    	std::cout <<"                            ***********************************************************\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *             Hotel Room Booking and Management System    *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *    1. Admin                                             *\n";
        std::cout << "                            *    2. User                                              *\n";
        std::cout << "                            *    3. Exit                                              *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *    Enter the option to go to the respective section:    *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            ***********************************************************\n";
        getch();
}
void Firstmenu()
{   cout<<"\n \n \n \n";
    cout<<"1st menu\n";
       std::cout << "                   *******************************************************************\n";
        std::cout << "                   *                          Admin 1st Menu                         *\n";                                                     
        std::cout << "                   *    1. Login                                                     *\n";
        std::cout << "                   *    2. Register                                                  *\n";
        std::cout << "                   *    Enter the option to perform respective action:               *\n";
        std::cout << "                   *                                                                 *\n";
        std::cout << "                   *******************************************************************\n";
        std::cout << "Option: ";
         getch();
}
void secondmenu()
{   cout<<"\n \n \n \n";
std::cout <<"                            ***********************************************************\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *             2nd menu                                    *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *    1. Report                                            *\n";
        std::cout << "                            *    2. Room management                                   *\n";
        std::cout << "                            *    3. User detail modification                          *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            *    Enter the option to go to the respective section:    *\n";
        std::cout << "                            *                                                         *\n";
        std::cout << "                            ***********************************************************\n";
 getch();

}
void UserDetailModi()
{   cout<<"\n \n \n \n";
        std::cout << "                         *****************************************************" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *         USER DETAIL MODIFICATION                  *" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *  1. Edit-User Data                                *" << std::endl;
        std::cout << "                         *  2. Check-in                                      *" << std::endl;
        std::cout << "                         *  3. Check-out                                     *" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *****************************************************" << std::endl;
 getch();
}
void roommanagement()
{
    cout<<"3rd memu\n";
      std::cout << "                                 ******************************************************\n";
        std::cout << "                               *                 ROOM MANAGEMENT SYSTEM             *\n";
        std::cout << "                               *  1. Edit Room                                      *\n";
        std::cout << "                               *  2. Add Room                                       *\n";
        std::cout << "                               *  3. Delete Room                                    *\n";
        std::cout << "                               *  4. Add Room Feature                               *\n";
        std::cout << "                               *  5. Delete Room Feature                            *\n";
        std::cout << "                               *                                                    *\n";
        std::cout << "                               * Enter the option to perform the respective action: *\n";
        std::cout <<"                                ******************************************************\n";
        std::cout << "Option: "; getch();
}
void usersection()
{   cout<<"\n \n \n \n";
    cout<<"4th menu";
        std::cout << "                         *****************************************************" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *                 USER SECTION                      *" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *  1. Check-In                                      *" << std::endl;
        std::cout << "                         *  2. Check-out                                     *" << std::endl;
        std::cout << "                         *  3. My detail                                     *" << std::endl;
        std::cout << "                         *                                                   *" << std::endl;
        std::cout << "                         *****************************************************" << std::endl;
        std::cout << "Enter your choice (1-3): ";
        getch();


}

int login()
{
    string userID, userpw, uID, Upass;
    int count;
    cout << "Enter your username:";
    cin >> userID;
    cout << "Enter your Password:";
    cin >> userpw;

    ifstream infile("records.txt");
    while (infile >> uID >> Upass)
    {

        if (userID == uID)
        {
            cout << "Username matched" << endl;
            if (userpw == Upass)
            {
                cout << "password matched" << endl;
                count = 1;
            }
        }
    }
    infile.close();
    if (count == 1)
    {
        cout << "You have logged in  successfully.You can now proceed further." << endl;
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
                    cout<<"Report section:";
                    cout << "\nNull, work on the progress...........";
                    cout << "Press m or M to goto mainmenu";
                    cin >> r;
                    if (r == 'm' || r == 'M')
                    {
                        return true;
                    }
                    else
                        break;
                case 2:
                    cout << "Room management menu: ";
                    roommanagement();
                     cout << "\nNull, work on the progress...........";
                    cout << "Press m or M to goto mainmenu";
                    cin >> r;
                    if (r == 'm' || r == 'M')
                    {
                        return true;
                    }
                    else
                        break;
                case 3:
                cout<<"User detail modicfication";
                UserDetailModi();
                 cout << "\nNull, work on the progress...........";
                    cout << "Press m or M to goto mainmenu";
                    cin >> r;
                    if (r == 'm' || r == 'M')
                    {
                        return true;
                    }
                    else
                        break;
                default :
                    cout << "Wrong Entry try again!!";
                }
            }
            else 
            return false;
}
void Register()
{
     string userID, userpw;
    cout<<"For Registration ";
    cout << "Enter your username:";
    cin >> userID;
    cout << "Enter your Password:";
    cin >> userpw;

    ofstream outfile("records.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << userID << " " << userpw << endl;
        outfile.close();
        cout << "Registration successfull";
    }
    else
    {
        cout << "Couldn't open file";
    }
    // main();
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
    start:
        int AdmOpt;
        Firstmenu();
        cin >> AdmOpt;
        switch (AdmOpt)
        {
        case 1:
        bool s;
            cout << "\t\tLogin page";
            s=loginsystem();
            if(s=true)
            {
                main();
            }
            else break;
                break;
        case 2:
            Register();
            cout << "Press m or M to goto mainmenu: ";
            cin >> r;
            if (r == 'm' || r == 'M')
            {
                main();
            }
            else
                break;
        default :
            {
                cout << "Wrong Entry try again!!";
                goto start;
            }
        }
        break;
    case 2:
        cout << "User section:";  usersection(); break;

    case 3:
        cout << "We are exiting.!! Thank you.";
        exit(0);
    default: 
        cout << "Wrong Entry try again!!";
        main();
    }

    return 0;
}

