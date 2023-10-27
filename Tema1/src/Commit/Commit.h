#pragma once
#include <string>

class Commit {
private:
    int id;
    char* message;
    int data; 

public:
    Commit(int id, const char* message, int data);
    Commit(const Commit& other); 
    Commit(Commit&& other) noexcept; 
    ~Commit();
    int getId() const;
    char* getMessage() const;
    int getData() const;
    void exampleModifyMessage();

};
