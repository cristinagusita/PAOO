#include "Commit.h"
#include<iostream>

Commit::Commit(int id, const std::string message, int data) {
    std::cout<<"I am the commit constructor!"<<"\n";
    this->id = id;
    this->message = message;
    this->data = data;
}

Commit::Commit(const Commit& other) {
    std::cout<<"I am the COPY constructor!"<<"\n";
        this->id = other.id;
        this->message = other.message;
        this->data = other.data;
    }

Commit::Commit(Commit&& other) noexcept {
        std::cout<<"I am the MOVE constructor!"<<"\n";
        this->id = other.id;
        this->message = other.message;
        this->data = other.data;   
        other.id = 0;
        other.message = "";
        other.data = 0;
}

Commit::~Commit() {
    std::cout<<"I am the commit destructor!"<<"\n";
}

int Commit::getId() const {
    return id;
}

std::string Commit::getMessage() const {
    return message;
}

int Commit::getData() const {
    return data;
}

void Commit::exampleModifyMessage() {
    this->message[0] = 'c';
}