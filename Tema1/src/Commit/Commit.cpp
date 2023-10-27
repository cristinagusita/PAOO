#include "Commit.h"
#include<iostream>
#include<cstring>

Commit::Commit(int id, const char* message, int data) {
    std::cout<<"I am the commit constructor!"<<"\n";
    this->id = id;
    this->message = new char[strlen(message)+1];
    strcpy(this->message, message);
    this->data = data;
}

Commit::Commit(const Commit& other) {
        std::cout<<"I am the COPY constructor!"<<"\n";
        this->id = other.id;
        this->message = new char[strlen(other.message)+1];
        strcpy(this->message, other.message);
        this->data = other.data;
    }

Commit::Commit(Commit&& other) noexcept {
        std::cout<<"I am the MOVE constructor!"<<"\n";
        this->id = other.id;
        this->message = other.message;
        this->data = other.data;   
        other.id = 0;
        other.message = nullptr;
        other.data = 0;
}

Commit::~Commit() {
    std::cout<<"I am the commit destructor!"<<"\n";
    delete[] message;
}

int Commit::getId() const {
    return id;
}

char* Commit::getMessage() const {
    return message;
}

int Commit::getData() const {
    return data;
}

void Commit::exampleModifyMessage() {
    this->message[0] = 'c';
}