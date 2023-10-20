#include "cat.h"
#include <iostream>

Cat::Cat(char *name){
    this->name = name;
}

char *Cat::get_name(){
    return this->name;
}

void Cat::set_name(char *name){
    this->name = name;
}

void Cat::print_name(){
    std::cout << this->name <<"\n";
}