#pragma once


#include <fstream>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>

#include "Data.hpp"
#include "list.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::getline;
using namespace std;


struct Player
{
    string name;
    int points = 0;

};


class play_game
{
public:


    fstream com_def_file;
    fstream player_class;

    void main_menu();

    void runner(int x, List<Data<string, string>>& com_def_list, int numofP, Player persons[]);


    inline void hello()
    {
        cout<<"Hello World";
    }
    void import_commands_def(fstream& file, List<Data<string, string>>& list);

    int import_player(fstream& file, Player players[]);

    void store_com_def(fstream& file, List<Data<string, string>>& list);

    void store_player(fstream& file, Player players[]);

    void questions(int num_Q, Player& players, List<Data<string, string>>& list);

    void delete_from_list(List<Data<string, string>>& list, string com_nam);

    /*void delete_com(string com_name, List<Data<string, string>>& list);*/


};





