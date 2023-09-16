#pragma once
#include <fstream>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename C, typename D>

class Data
{
public:

    Data();

    Data(C commands, D definitions);



    void set_com(C coms);
    string get_com();
    void set_deffy(D def);
    string get_deffy();




private:

    C command;
    D definition;




};






template <typename C, typename D>
inline Data<C, D>::Data()
{
    command = "";
    definition = "";
}

template <typename C, typename D>
inline Data<C, D>::Data(C commands, D definitions)
{
    command = commands;
    definition = definitions;
}


template <typename C, typename D>
inline void Data<C, D>::set_com(C coms)
{
    command =  coms;
}

template <typename C, typename D>
inline string Data<C, D>::get_com()
{
    return command;
}

template <typename C, typename D>
inline void Data<C, D>::set_deffy(D def)
{
    definition = def;
}


template <typename C, typename D>
inline string Data<C, D>::get_deffy()
{
    return definition;
}
