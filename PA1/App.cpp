#include "App.hpp"
#include "Data.hpp"
#include "game_rules.hpp"
#include <iostream>

using namespace std;



void play_game::main_menu()
{

   
    
    int numofP;
    List<Data<string, string>> com_def_list;
  
    import_commands_def(com_def_file, com_def_list);
   
    Player persons[200];



    numofP = import_player(player_class, persons);
    
    int x = 0;
    do
    {
        
        cout << "Welcome To The Linux Matching Game!!" << endl;
        cout << endl;
        cout << "1. Game Rules" << endl;
        cout << "2. Play Game" << endl;
        cout << "3. Load Prev Game" << endl;
        cout << "4. Add Command" << endl;
        cout << "5. Remove Command" << endl;
        cout << "6. Exit :(" << endl;

        cout << endl;
        cout << endl;
        cout << "OPTION : ";
        cin >> x;

        if (x > 0 && x < 7)
        {
            runner(x, com_def_list, numofP, persons);
        }
       

    } while (x != 6 );




    return;

};


void play_game::runner(int x, List<Data<string, string>>& com_def_list,int numofP, Player persons[])
{

    int numofQ = 0;
    
    int player_num = 0;
    int temp_array_num = 0;
    string temp_name;
    string new_com;
    string t;
    string new_def;
    Data<string, string> mpData;

    

    


    switch (x)
    {
    case 1:
        game_rules();

        break;
        ///////////////////////////////////////////////////////////////////////////////////
    case 2:
        
        cout << "Welcome to the game!" << endl;
        cout << "What is your name?  ";
        cin >> temp_name;
        if (numofP == 0)
        {
            temp_array_num = numofP;
        }
        else {
            temp_array_num = numofP ;
        }

        persons[temp_array_num].name = temp_name;
        cout << "Awesome!!" << endl;
        cout << "How many Questions do you want?   ";
        cin >> numofQ;
        cout << "Lets Get Started" << endl;

        questions(numofQ, persons[temp_array_num], com_def_list);
        cout << "You are currently at : " << persons[temp_array_num].points << " Points" << endl;
       
        

        /////////////////////////////////////////////////////////////////////////////////
        break;
    case 3:
        
        cout << "What is your name? : ";
        cin >> temp_name;
        for (int i = 0; i <= numofP + 1; i++)
        {
            if (temp_name == persons[i].name)
            {
                cout << "Welcome Back " << persons[i].name << "You Currently Have: " << persons[i].points << " Points." << endl;
                player_num = i;
                break;
            }
        }
        cout << "How many Questions do you want?   ";
        cin >> numofQ;
        cout << "Lets Get Started" << endl;

        questions(numofQ, persons[player_num], com_def_list);
        cout << "You are currently at : " << persons[player_num].points << " Points" << endl;
        
        

        break;
        /////////////////////////////////////////////////////////////////////////////////
    case 4:
        
        cout << "Which Command Would You Like To Add?" << endl;
        cout << "Enter Here: ";
        cin >> new_com;
        cout << endl;
        std::cin.ignore();
        cout << "What is the Definiton for It?" << endl;
        cout << "Enter Here: ";
        std::getline(std::cin, new_def);
        mpData.set_com(new_com);
        mpData.set_deffy(new_def);

        com_def_list.insert(mpData);

       
        cout << "Succefully Saved!!" << endl;



        break;
        /////////////////////////////////////////////////////////////////////////////////
    case 5:
        
        cout << "Which Command Would You Like To Delete?" << endl;
        cout << "Enter Here: ";
        cin >> new_com;
        cout << endl;

        
        delete_from_list(com_def_list, new_com);

        cout << "Succefully Saved!!" << endl;



        break;
        /////////////////////////////////////////////////////////////////////////////////
    case 6:


        store_com_def(com_def_file, com_def_list);
        store_player(player_class, persons);

        break;



    }
    

}








void play_game :: import_commands_def(fstream& file, List<Data<string, string>>& list)
{
    string com;
    string deffy;
    string fill;
    Data<string, string> temp;
    


    

    file.open("command.csv", fstream::in);
    if (!file.is_open()) {
        cout<<"Error Opening File"<<endl;
          return;
        }   

    getline(file, com, ',');
    getline(file, fill, '"');
    getline(file, deffy, '"');

    temp.set_com(com);
    temp.set_deffy(deffy);

    list.insert(temp);

    while (!file.eof())
    {
        getline(file, fill, '\n');
        getline(file, com, ',');
        getline(file, fill, '"');
        getline(file, deffy, '"');

        temp.set_com(com);
        temp.set_deffy(deffy);

        list.insert(temp);
    }

    


    file.close();
}

int  play_game::import_player(fstream& file, Player players[])
{
    int x = 0;

    string name;
    string point;
    file.open("profiles.csv", fstream::in);

    while (getline(file, name, ','))
    {
        getline(file, point);
        players[x].name = name;
        players[x].points = (stoi(point));

        x++;
    }
    file.close();
    return x;
   
}

void  play_game::questions(int num_Q, Player& players, List<Data<string, string>>& list)
{
    
   
    Player* temp_player = &players;

    

    for (int i = 0; i < num_Q; i++)
    {
        int answer = 0;
        Node <Data<string, string>>* temp_1;
        Node <Data<string, string>>* temp_2;
        Node <Data<string, string>>* temp_3;
        int incorrect_1 = 0;
        int incorrect_2 = 0;
        int correct = 0;


        do
        {
            correct = rand() % 50;
            temp_1 = list.trav_node(correct);
        } while (temp_1->get_read() == 1);


        do
        {
            incorrect_1 = rand() % 50;

        } while (incorrect_1 == correct);


        do
        {
            incorrect_2 = rand() % 50;

        } while (incorrect_2 == correct && incorrect_2 == incorrect_1);



        int position = rand() % 50;

        cout << endl;


        temp_2 = list.trav_node(incorrect_1);
        temp_3 = list.trav_node(incorrect_2);

        temp_1->if_read();

        if (position == 0)
        {
            cout << temp_1->getData().get_com() << endl;
            cout << "1. " << temp_1->getData().get_deffy() << endl;
            cout << "2. " << temp_2->getData().get_deffy() << endl;
            cout << "3. " << temp_3->getData().get_deffy() << endl;

            cout << "Enter Here :";
            cin >> answer;
            if (answer == 1)
            {
                cout << "Correct" << endl;
                temp_player->points++;
            }
            else {
                cout << "Incorrect" << endl;
                temp_player->points--;
            }

        }
        else if (position == 1)
        {
            //i,c,i
            cout << temp_1->getData().get_com() << endl;

            cout << "1. " << temp_2->getData().get_deffy() << endl;
            cout << "2. " << temp_1->getData().get_deffy() << endl;
            cout << "3. " << temp_3->getData().get_deffy() << endl;

            cout << "Enter Here :";
            cin >> answer;
            if (answer == 2)
            {
                cout << "Correct" << endl;
                temp_player->points++;
            }
            else {
                cout << "Incorrect" << endl;
                temp_player->points--;
            }
        }
        else {
            //i,i,c
            cout << temp_1->getData().get_com() << endl;

            cout << "1. " << temp_2->getData().get_deffy() << endl;
            cout << "2. " << temp_3->getData().get_deffy() << endl;
            cout << "3. " << temp_1->getData().get_deffy() << endl;

            cout << "Enter Here :";
            cin >> answer;
            if (answer == 3)
            {
                cout << "Correct" << endl;
                temp_player->points++;
            }
            else {
                cout << "Incorrect" << endl;
                temp_player->points--;
            }



        }


    

    }
};

void  play_game::store_player(fstream& file, Player players[])
{
    int x = 0;
    file.open("profiles.csv", fstream::out);

    do
    {
        file << players[x].name << ", " << players[x].points << endl;
        

        x++;
    } while (players[x].name != "" || x > 100);


    file.close();
}

void play_game::store_com_def(fstream& file, List<Data<string, string>>& list)
{
    Node<Data<string, string>>* temp;
    temp = list.getHead();
    
    file.open("command.csv", fstream::out);
  
    do 
    {
        file << temp->getData().get_com() << "," << '"' << temp->getData().get_deffy() << '"' << endl;

        temp = temp->getNextPtr();
       
    } while (temp->getNextPtr() != list.getTail());

    
    file << list.getTail()->getData().get_com() << "," << '"' << list.getTail()->getData().get_deffy() << '"';


       
    file.close();

}

void play_game :: delete_from_list(List<Data<string, string>>& list, string com_nam)
{
    Node<Data<string, string>>* temp;
    Node<Data<string, string>>* temp2;

    temp = list.getHead();
    temp2 = list.getHead()->getNextPtr();


    while (temp2 != list.getTail())
    {
        if (temp2->getData().get_com() == com_nam)
        {
            if (temp2->getData().get_com() == list.getTail()->getData().get_com())
            {
                temp->setNextPtr(list.getHead());
                list.setTail(temp);
                delete temp2;
                break;
            }
            else
            {
                temp->setNextPtr(temp2->getNextPtr());
                delete temp2;
                break;
            }
           
        }
        temp = temp->getNextPtr();
        temp2 = temp->getNextPtr();
    }

    
}

