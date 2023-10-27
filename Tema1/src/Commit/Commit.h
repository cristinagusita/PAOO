#pragma once
#include <string>

class Commit {
private:
    int id;
    std::string message;
    int data; 

public:
    Commit(int id, const std::string message, int data);
    Commit(const Commit& other); 
    Commit(Commit&& other) noexcept; 
    ~Commit();
    int getId() const;
    std::string getMessage() const;
    int getData() const;
    void exampleModifyMessage();

};
