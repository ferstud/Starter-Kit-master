#ifndef PF_HELPER
#define PF_HELPER

#include "helper.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

namespace pf
{
    void PrintGameSettings(){
        std::cout << "Default Game Settings";
        std::cout << "\n--------------------\n";
        std::cout << "Board Rows     : " << kRows << std::endl;
        std::cout << "Board Columns  : " << kColumns << std::endl;
        std::cout << "Zombie Count   : " << zombie_count << std::endl;
    }

    void ChangeGameSettings(){
        int z_count;

        ClearScreen();
        std::cout << "Board Settings\n";
        std::cout << "--------------------\n";
        do {
            std::cout << "Enter rows => ";
            std::cin >> kRows;
            if(std::cin.fail() || kRows < 3 || kRows % 2 == 0){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "\nInvalid Input!! Enter an odd number, must be greater than 3.\n\n";
            }
        }while( kRows < 3 || kRows % 2 == 0 );

        do {
            std::cout << "Enter Columns => ";
            std::cin >> kColumns;
            if(std::cin.fail() || kColumns < 3 || kColumns % 2 == 0){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "\nInvalid Input!! Enter an odd number, must be greater than 3.\n\n";
            }
        }while( kColumns < 3 || kColumns % 2 == 0 );

        std::cout << "\nZombie Settings\n";
        std::cout << "---------------------";

        while(1){
            std::cout << "\nEnter number of zombies(1-9): ";
            std::cin >> z_count;
            if(std::cin.fail() || z_count<1 || z_count>9) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "\nInvalid Input! Zombies can only be in range 1-9\n";
            }
            else{
                zombie_count = z_count;
                break;
            }
        }
        std::cout << "\nSettings Updated.\n\n";
        Pause();
    }

    void Help(){
        std::cout << "\nCommands\n";
        std::cout << "up\t-Alien to move up\n";
        std::cout << "down\t-Alien to move down\n";
        std::cout << "left\t-Alien to move left\n";
        std::cout << "right\t-Alien to move right\n";
        std::cout << "arrow\t-Change the direction of an arrow\n";
        std::cout << "help\t-Display these user commands\n";
        std::cout << "save\t-Save the game\n";
        std::cout << "load\t-Load a game\n";
        std::cout << "quit\t-Quit the game\n\n";
        Pause();
    }

    bool GameOver()
    {
        if( alien.life == 0 )   // alien dead
            return true;

        for(int i = 0; i < zombie_count; i++)
            if(zombies[i].isAlive)      // zombie is still alive
                return false;

        return true;        // all zombies are dead
    }

    void DeleteGameBoard()
    {
        int i;
        if(board != NULL){
            for(i=0; i<kRows; i++)
                delete[] board[i];
            delete[] board[i];
        }
        if(zombies != NULL)
            delete[] zombies;
    }

    void Caps_to_small(std::string &a)
    {
        for(int i=0;i<a.size();i++){
            if(a[i]>=65 && a[i]<=90)
                a=a[i]+32;
        }
    }
    
       void ChangeArrow()
    {
        int r_no, c_no;
        std::string direction;
        do{
            std::cout << "\nEnter Row Number => ";
            std::cin >> r_no;

            if(std::cin.fail() || r_no < 1 || r_no > kRows)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "\nInvalid Input!!\n";
            }
        }while(r_no < 1 || r_no > kRows);

        do{
            std::cout << "\nEnter Column Number => ";
            std::cin >> c_no;

            if(std::cin.fail() || c_no < 1 || c_no > kColumns)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "\nInvalid Input!!\n";
            }
        }while(c_no < 1 || c_no > kColumns);

        r_no--;
        c_no--;

        std::cin.ignore();
        do{
            std::cout << "\nEnter Direction => ";
            std::cin >> direction;

            Caps_to_small(direction);
            if(direction != "up" && direction != "down" && direction != "left" && direction != "right")
            {
                std::cout << "\nInvalid Input!!\n";
            }
        }while(direction != "up" && direction != "down" && direction != "left" && direction != "right");

        if( board[r_no][c_no].arrow ) {
            if(direction == "up"){
                board[r_no][c_no].arrow = 1;
                board[r_no][c_no].representation = '^';
            }
            else if(direction == "right"){
                board[r_no][c_no].arrow = 2;
                board[r_no][c_no].representation = '>';
            }
            else if(direction == "down"){
                board[r_no][c_no].arrow = 3;
                board[r_no][c_no].representation = 'v';
            }
            if(direction == "left"){
                board[r_no][c_no].arrow = 4;
                board[r_no][c_no].representation = '<';
            }
        } else {
            std::cout << "\nSelected Cell is not an arrow.\n\n";
        }

        std::cin.ignore();
    }

    char isCharacter(int r_no, int c_no)
    {
        int i, j;
        if(board[r_no][c_no].is_alien) {
            return alien.representation;
        }

        for(i = 0; i < zombie_count; i++)
        {
            if( zombies[i].row_no == r_no && zombies[i].col_no == c_no ){
                return zombies[i].representation;
            }
        }
        return 'N';
    }

    void SetRandomObject(int i, int j)
    {
        int num = rand() % 10 + 1;  // generating random number from 1 to 10
        // assigning objects randomly
        // 1 : arrow up
        // 2 : arrow right
        // 3 : arrow down
        // 4 : arrow left
        // 5,6 : health
        // 7,8 : pod
        // 9 : rock
        // 10 : empty
        if( num >= 1 && num <= 4 )  // arrow
        {
            board[i][j].is_rock = 0;
            board[i][j].pod = 0;
            board[i][j].is_health = 0;
            board[i][j].is_zombie = false;
            board[i][j].is_alien = false;
            board[i][j].is_empty = false;
            board[i][j].arrow = num;

            if(num == 1)
                board[i][j].representation = '^';
            else if(num == 2)
                board[i][j].representation = '>';
            else if(num == 3)
                board[i][j].representation = 'v';
            else if(num == 4)
                board[i][j].representation = '<';
        }
        else if ( num == 5 || num == 6)
        {
            board[i][j].is_rock = 0;
            board[i][j].pod = 0;
            board[i][j].is_zombie = false;
            board[i][j].is_alien = false;
            board[i][j].is_empty = false;
            board[i][j].arrow = 0;
            board[i][j].representation = 'h';
            board[i][j].is_health = 20;
        }
        else if ( num == 7 || num == 8)
        {
            board[i][j].is_rock = 0;
            board[i][j].pod = 10;
            board[i][j].is_zombie = false;
            board[i][j].is_alien = false;
            board[i][j].is_empty = false;
            board[i][j].arrow = 0;
            board[i][j].representation = 'p';
            board[i][j].is_health = 0;
        }
        else if ( num == 9)
        {
            board[i][j].is_rock = rand() % 8 + 1;
            board[i][j].pod = 0;
            board[i][j].is_zombie = false;
            board[i][j].is_alien = false;
            board[i][j].is_empty = false;
            board[i][j].arrow = 0;
            board[i][j].representation = 'r';
            board[i][j].is_health = 0;
        }
        else
        {
            board[i][j].is_rock = 0;
            board[i][j].pod = 0;
            board[i][j].is_zombie = false;
            board[i][j].is_alien = false;
            board[i][j].is_empty = true;
            board[i][j].arrow = 0;
            board[i][j].representation = ' ';
            board[i][j].is_health = 0;
        }
    }

    void CreateGameBoard()
    {
        int i, j, r, c, num;
        // assigning the memory
        board = new Cell * [kRows];
        for(i=0; i<kRows; i++)
            board[i] = new Cell[kColumns];
        zombies = new Character[zombie_count];

        // setting allien attributes
        alien.attack = 0;
        alien.row_no = kRows / 2;
        alien.col_no = kColumns / 2;
        alien.life = rand() % 201 + 100;    // between 100 and 300
        alien.range = 0;
        alien.representation = 'A';

        // Setting zombies attributes
        for(i=0; i<zombie_count; i++)
        {
            zombies[i].life = rand() % 251 + 50;     // between 50 and 250
            zombies[i].attack = rand() % (zombies[i].life - 30) + 10;
            zombies[i].row_no = -1;
            zombies[i].col_no = -1;
            zombies[i].range = rand() % std::min(kRows, kColumns);
            zombies[i].representation = (i + 1) + '0';
            zombies[i].isAlive = true;
        }

        // placing characters on board
        board[alien.row_no][alien.col_no].representation = alien.representation;
        board[alien.row_no][alien.col_no].is_alien = true;

        for(i=0; i<zombie_count; i++)
        {
            do{
                r = rand() % kRows;
                c = rand() % kColumns;
            } while (isCharacter(r, c) != 'N');
            zombies[i].row_no = r;
            zombies[i].col_no = c;
            board[r][c].representation = zombies[i].representation;
            board[r][c].is_zombie = true;
        }

        // Placing Random Objects in the board
        for(i = 0; i < kRows; i++)
        {
            for( j = 0; j < kColumns; j++)
            {
                if ( !(i == alien.row_no && j == alien.col_no) )
                    board[i][j].is_alien = false;

                if(isCharacter(i, j) != 'N') {
                    continue;
                }

                SetRandomObject(i, j);
            }
        }
    }

    void ShowGameBoard(){

        std:cout << "\t .: Alien vs Zombie :.\n\n";

        std:cout << std::setw(5) << std::right;

        int prefix=1, f_cols=1, no_cols=9, no_col=9;

        for(int i=1;i<=9 && f_cols<=kColumns;i++,f_cols++){ //displaying first 9 column numbers
            std::cout << i << " ";
        }

        for(int k=1;k<=(kColumns/10);k++){
            for(int j=0;j<=9 && no_cols < kColumns ;j++,no_cols++){ //displaying first digit
                std::cout << prefix << " ";
            }
            prefix++;
        }
        if(kColumns>9)
            std::cout << std::endl;
        std::cout << std::setw(23) << std::right;
        for(int k=1;k<=(kColumns/10);k++){
            for (int j = 0; j <= 9 && no_col < kColumns; j++, no_col++) { //displaying remaining digits
                std::cout << j << " ";
            }
        }

        //dislaying board
        std::cout << "\n";
        std::cout << std::setw(5);
        for(int i=0;i<kColumns;i++){
            std::cout << "+-";
        }
        std::cout << "+\n";
        for(int j=0;j<kRows;j++){
            std::cout << std::setw(3) << std::left << j+1; //displaying rows
            for(int i=0;i<kColumns;i++){
                std::cout << "|" << board[j][i].representation;
            }
            std::cout << "| ";
            std::cout << std::endl;
            std::cout << std::setw(5) << std::right;
            for(int i=0;i<kColumns;i++){ //displaying columns
                std::cout << "+-";
            }
            std::cout << "+\n";
        }

        std::cout << "\n\n";
    }

    int GetClosestZombie(int r, int c)
    {
        int i, minDistance = 99, minDisIndex, distance;
        for(i = 0; i < zombie_count; i++)
        {
            distance = std::min(abs(zombies[i].row_no - r), abs(zombies[i].col_no - c));
            if( minDistance > distance ) {
                minDistance = distance;
                minDisIndex = i;
            }
        }
        return i;
    }

    bool CanAttack(int r, int c, int range)
    {
        if( (abs( r - alien.row_no ) <= range) && (abs( c - alien.col_no ) <= range) )
            return true;
        return false;
    }

    void ResetTrail()
    {
        int i, j;
        for(i = 0; i < kRows; i++)
        {
            for( j = 0; j < kColumns; j++ )
            {
                if(board[i][j].representation == '.')
                    SetRandomObject(i, j);
            }
        }
    }


    void Turn(int t){
        if(t==0)
            std::cout << "-->";
        std::cout << "\tAlien\t: Life  " << alien.life << ", Attack  " << alien.attack << std::endl;
        for(int i=0;i<zombie_count;i++){
            if(t==i+1)
                std::cout << "->\tZombie" << i+1 << "\t: Life  " << zombies[i].life << ", Attack  " << zombies[i].attack << ", Range  " << zombies[i].range << std::endl;
            else
                std::cout << "\tZombie" << i+1 << "\t: Life  " << zombies[i].life << ", Attack  " << zombies[i].attack << ", Range  " << zombies[i].range << std::endl;
        }
    }


    int ClearScreen()
    {
#if defined(_WIN32)
        return std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
        return std::system("clear");
#endif
    }

    int Pause()
    {
#if defined(_WIN32)
        return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
        return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
    }

}
#endif
