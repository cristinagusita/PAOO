#include "MergeCommit.h"

using namespace MyGit;

MergeCommit::MergeCommit(const char* message, const char* mergeDetails) : Commit(message) {
    this->mergeDetails = new char[strlen(mergeDetails) + 1];
    strcpy(this->mergeDetails, mergeDetails);
}

MergeCommit::MergeCommit(const MergeCommit& other) : Commit(other) {
    this->mergeDetails = new char[strlen(other.mergeDetails) + 1];
    strcpy(this->mergeDetails, other.mergeDetails);
}

MergeCommit::MergeCommit(MergeCommit&& other) noexcept : Commit(std::move(other)) {
    this->mergeDetails = other.mergeDetails;
    other.mergeDetails = nullptr;
}

MergeCommit::~MergeCommit() {
    delete[] this->mergeDetails;
}

MergeCommit& MergeCommit::operator=(const MergeCommit& other) {
    if (this != &other) {
        Commit::operator=(other);
        delete[] this->mergeDetails;
        this->mergeDetails = new char[strlen(other.mergeDetails) + 1];
        strcpy(this->mergeDetails, other.mergeDetails);
    }
    return *this;
}

MergeCommit& MergeCommit::operator=(MergeCommit&& other) noexcept {
    if (this != &other) {
        Commit::operator=(std::move(other));
        delete[] this->mergeDetails;
        this->mergeDetails = other.mergeDetails;
        other.mergeDetails = nullptr;
    }
    return *this;
}

bool MergeCommit::operator==(const MergeCommit& other) const {
    return Commit::operator==(other) && (strcmp(this->mergeDetails, other.mergeDetails) == 0);
}

bool MergeCommit::operator!=(const MergeCommit& other) const {
    return !(*this == other);
}

void MergeCommit::setMergeDetails(const char* details) {
    this->mergeDetails = new char[strlen(details) + 1];
    strcpy(this->mergeDetails, details); 
}

const char* MergeCommit::getMergeDetails() const {
    return this->mergeDetails;
}

void MergeCommit::display() const {
    std::cout<<"MergeCommit: "<<"\n";
    std::cout<<"\tId: "<<this->getId()<<"\n";
    std::cout<<"\tMessage: "<<this->getMessage()<<"\n";
    std::cout<<"\tMerge details: "<<this->mergeDetails<<"\n";
}
