#ifndef PF_HELPER_H
#define PF_HELPER_H

#include <iostream>

namespace pf
{
    class Cell{
        public:
            int is_rock;
            int pod;
            int arrow; // 0 = no arrow, 1 = up, 2 = right, 3 = down, 4 = left
            int is_health;
            bool is_zombie;
            bool is_alien;
            bool is_empty;
            char representation;
    };

    class Character{
        public:
            int row_no;
            int col_no;
            int life;
            int attack;
            int range;
            bool isAlive;
            char representation;
    };

    // helper variables
    int kRows = 5;
    int kColumns = 9;
    int zombie_count = 1;
    Cell **board=NULL;
    Character alien;
    Character *zombies=NULL;

    // helper functions
    void PrintGameSettings();
    void ChangeGameSettings();
    void Help();
    bool GameOver();
    void DeleteGameBoard();
    void Caps_to_small(std::string &a);
    void ChangeArrow();
    char isCharacter(int r_no, int c_no);
    void SetRandomObject(int i, int j);
    void CreateGameBoard();
    void ShowGameBoard();
    int GetClosestZombie(int r, int c);
    bool CanAttack(int r, int c, int range);
    void ResetTrail();
    int ClearScreen();
    int Pause();
}

#endif