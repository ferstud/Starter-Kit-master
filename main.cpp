// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TxxL 
// Names: MEMBER_NAME_1 | MEMBER_NAME_2 | MEMBER_NAME_3 
// IDs: MEMBER_ID_1 | MEMBER_ID_2 | MEMBER_ID_3 
// Emails: MEMBER_EMAIL_1 | MEMBER_EMAIL_2 | MEMBER_EMAIL_3 
// Phones: MEMBER_PHONE_1 | MEMBER_PHONE_2 | MEMBER_PHONE_3 
// ********************************************************* 


#include "helper.cpp"
#include <iostream>
#include <string>

using namespace std;

void Caps_to_small(string &a);

int main()
{
    char isPlay = true, choice;
    string input;

    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl << endl;


    do{
        pf::PrintGameSettings();
        do{
            std::cout << "\nDo you wish to change the game settings (y/n)? => ";
            cin >> choice;
            choice |= 32;
            if(choice == 'y')
                pf::ChangeGameSettings();
            else if(choice == 'n')
                break;
            else
                std::cout << "\nInvalid Input!\n";
        }while( !(choice == 'n' || choice == 'y') );

        pf::CreateGameBoard();

        cin.ignore();
        while( !pf::GameOver() )
        {
            pf::ClearScreen();
            pf::ShowGameBoard();
            cout << "Command> ";
            getline(cin, input, '\n');
            Caps_to_small(input);

            // will move alien later
            if(input=="up") {
                cout << "Alien Move\n";
            }
            else if(input=="down") {
                cout << "Alien Move\n";
            }
            else if(input=="left") {
                cout << "Alien Move\n";
            }
            else if(input=="right") {
                cout << "Alien Move\n";
            }
            else if(input=="arrow") {
                pf::ChangeArrow();
            }
            else if(input=="help") {
                pf::Help();
            }
            else if(input=="save") {
                cout << "saving\n";
            }
            else if(input=="load") {
                cout << "loading\n";
            }
            else if(input=="quit") {
                cout << "\nAre you sure? (y/n) : ";
                cin >> choice;
                std::cin.ignore();
                choice |= 32;
                if(choice == 'y') {
                    cout << "Goodbye!\n";
                    break;
                }
                else
                    cout << "Aborting...\n";
                pf::Pause();
            }
            else {
                cout << "\nInvalid Input!\n\n";
                pf::Pause();
            }
        }

        pf::DeleteGameBoard();
        cout << "\nDo you want to Play Again? (y/n) : ";
        cin >> choice;

        choice |= 32;

        if(choice == 'y')
            isPlay = true;
        else
            isPlay = false;

    }while( isPlay );

    pf::Pause();
    return 0;
}

void Caps_to_small(string &a){
    for(int i=0;i<a.size();i++){
        if(a[i]>=65 && a[i]<=90)
            a=a[i]+32;
    }
}