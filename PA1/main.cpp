#include <iostream>

#include "App.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::getline;
using namespace std;

/*ADVANTAGES/DISADVANTAGES LINKED LIST: Advantage: Having a Linked list allows you to have dynamic sizing, 
this is useful because of the constant adding to the list. Disadvantage: Acessing specific points in the linked list isnt nearly as good as an array,
you have to traverse instead of just select.*/


/*ADVANTAGES/DISADVANTAGES ARRAY:  Advantage: Having an acess ready index, Disadvantage: Having a fixed size, its hard to have it dynamic, at least compared to a list
for obvious reasons*/


int main() {
   
   play_game runner;
   runner.main_menu();
   
    return 0;
}



