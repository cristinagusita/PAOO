#include "Commit.h"
#include <iostream>
#include <cstring>

int MyGit::Commit::idCounter = 0; 
std::mutex MyGit::Commit::mutex;

MyGit::Commit::Commit(const char* message) {
    std::lock_guard<std::mutex> lock(mutex);
    std::cout << "I am the commit constructor!\n";
    this->id = ++idCounter;
    this->message = std::shared_ptr<char[]>(new char[strlen(message)+1]);
    strcpy(this->message.get(), message);
}

MyGit::Commit::Commit(const Commit& other) {
        std::cout<<"I am the COPY constructor!"<<"\n";
        this->id = ++idCounter;
        this->message = std::shared_ptr<char[]>(new char[strlen(other.message.get())+1]);
        strcpy(this->message.get(), other.message.get());
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
}

MyGit::Commit& MyGit::Commit::operator=(const Commit& other) {
    std::cout<<"I am the copy assignment!"<<"\n";
    if (this != &other) {
        id = ++idCounter;
        message = std::shared_ptr<char[]>(new char[strlen(other.message.get())+1]);
        strcpy(message.get(), other.message.get());
    }
    return *this;
}


MyGit::Commit& MyGit::Commit::operator=(Commit&& other) noexcept {
    std::cout<<"I am the move assignment!"<<"\n";
    if (this != &other) {
        id = other.id;
        message = other.message;
        other.id = 0;
        other.message = nullptr;
    }
    return *this;
}

bool MyGit::Commit::operator==(const Commit& other) const {
    return (strcmp(message.get(), other.message.get()) == 0);
}

bool MyGit::Commit::operator!=(const Commit& other) const {
    return !(*this == other);
}


int MyGit::Commit::getId() const {
    return id;
}

std::weak_ptr<char[]> MyGit::Commit::getMessage() const {
    return message;
}

void MyGit::Commit::exampleModifyMessage() {
    this->message[0] = 'c';
}