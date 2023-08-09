#include <iostream>
#include <string>
using namespace std;
int main() {
    std::string word ;

cout<<"Enter your option:";
getline(cin,word);

    // Iterate through each character in the string
    for (char letter : word) {
        // int c;
        // c=letter;
       if(letter>=48&&letter<=58)
       {
       
        switch(letter)
        {
            case '1':
            {
            cout<<"went to option one"<<endl;
            break;
            }
            case '2':
            {
            cout<<"Went to option two "<<endl;
            break;
            }
            case '3':
            {
            cout<<"Went to option three "<<endl;
            break;
            }


        }
       }
        else if(letter==' '){
            cout<<"space"<<endl;

        }
    }
return 0;
}
/*
"works with only using the char and ascii value"*/