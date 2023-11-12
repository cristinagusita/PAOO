#include "Commit.h"
#include <iostream>
#include <cstring>

int MyGit::Commit::idCounter = 0; 

MyGit::Commit::Commit(const char* message) {
    std::cout<<"I am the commit constructor!"<<"\n";
    this->id = ++idCounter;
    this->message = new char[strlen(message)+1];
    strcpy(this->message, message);
}

MyGit::Commit::Commit(const Commit& other) {
        std::cout<<"I am the COPY constructor!"<<"\n";
        this->id = ++idCounter;
        this->message = new char[strlen(other.message)+1];
        strcpy(this->message, other.message);
    }

MyGit::Commit::Commit(Commit&& other) noexcept {
        std::cout<<"I am the MOVE constructor!"<<"\n";
        this->id = other.id;
        this->message = other.message;
        other.id = 0;
        other.message = nullptr;
}

MyGit::Commit::~Commit() {
    std::cout<<"I am the commit destructor!"<<"\n";
    delete[] message;
}

MyGit::Commit& MyGit::Commit::operator=(const Commit& other) {
    std::cout<<"I am the copy assignment!"<<"\n";
    if (this != &other) {
        delete[] message;
        message = new char[strlen(other.message) + 1];
        strcpy(message, other.message);
    }
    return *this;
}


MyGit::Commit& MyGit::Commit::operator=(Commit&& other) noexcept {
    std::cout<<"I am the move assignment!"<<"\n";
    if (this != &other) {
        delete[] message;
        id = other.id;
        message = other.message;
        other.id = 0;
        other.message = nullptr;
    }
    return *this;
}

bool MyGit::Commit::operator==(const Commit& other) const {
    return (strcmp(message, other.message) == 0);
}

bool MyGit::Commit::operator!=(const Commit& other) const {
    return !(*this == other);
}


int MyGit::Commit::getId() const {
    return id;
}

char* MyGit::Commit::getMessage() const {
    return message;
}

void MyGit::Commit::exampleModifyMessage() {
    this->message[0] = 'c';
}