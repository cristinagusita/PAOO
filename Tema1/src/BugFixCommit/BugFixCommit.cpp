#include "BugFixCommit.h"

using namespace MyGit;

BugFixCommit::BugFixCommit(const char* message, const char* bugDetails) : Commit(message) {
    this->bugDetails = new char[strlen(bugDetails) + 1];
    strcpy(this->bugDetails, bugDetails);
}

BugFixCommit::BugFixCommit(const BugFixCommit& other) : Commit(other) {
    this->bugDetails = new char[strlen(other.bugDetails) + 1];
    strcpy(this->bugDetails, other.bugDetails);
}

BugFixCommit::BugFixCommit(BugFixCommit&& other) noexcept : Commit(std::move(other)) {
    this->bugDetails = other.bugDetails;
    other.bugDetails = nullptr;
}

BugFixCommit::~BugFixCommit() {
    delete[] this->bugDetails;
}

BugFixCommit& BugFixCommit::operator=(const BugFixCommit& other) {
    if (this != &other) {
        Commit::operator=(other);
        delete[] this->bugDetails;
        this->bugDetails = new char[strlen(other.bugDetails) + 1];
        strcpy(this->bugDetails, other.bugDetails);
    }
    return *this;
}

BugFixCommit& BugFixCommit::operator=(BugFixCommit&& other) noexcept {
    if (this != &other) {
        Commit::operator=(std::move(other));
        delete[] this->bugDetails;
        this->bugDetails = other.bugDetails;
        other.bugDetails = nullptr;
    }
    return *this;
}

bool BugFixCommit::operator==(const BugFixCommit& other) const {
    return Commit::operator==(other) && (strcmp(this->bugDetails, other.bugDetails) == 0);
}

bool BugFixCommit::operator!=(const BugFixCommit& other) const {
    return !(*this == other);
}

void BugFixCommit::setBugDetails(const char* details) {
    this->bugDetails = new char[strlen(details) + 1];
    strcpy(this->bugDetails, details); 
}

const char* BugFixCommit::getBugDetails() const {
    return this->bugDetails;
}

void BugFixCommit::display() const {
    std::cout<<"BugFixCommit: "<<"\n";
    std::cout<<"\tId: "<<this->getId()<<"\n";
    std::cout<<"\tMessage: "<<this->getMessage()<<"\n";
    std::cout<<"\tBug details: "<<this->bugDetails<<"\n";
}



