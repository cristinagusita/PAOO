#include "BugFixCommit.h"

using namespace MyGit;

BugFixCommit::BugFixCommit(const char* message, const char* bugDetails) : Commit(message) {
    this->bugDetails = std::shared_ptr<char[]>(new char[strlen(bugDetails) + 1]);
    strcpy(this->bugDetails.get(), bugDetails);
}

BugFixCommit::BugFixCommit(const BugFixCommit& other) : Commit(other) {
    this->bugDetails = std::shared_ptr<char[]>(new char[strlen(other.bugDetails.get()) + 1]);
    strcpy(this->bugDetails.get(), other.bugDetails.get());
}

BugFixCommit::BugFixCommit(BugFixCommit&& other) noexcept : Commit(std::move(other)) {
    this->bugDetails = other.bugDetails;
    other.bugDetails = nullptr;
}

BugFixCommit::~BugFixCommit() {
}

BugFixCommit& BugFixCommit::operator=(const BugFixCommit& other) {
    if (this != &other) {
        Commit::operator=(other);
        this->bugDetails = std::shared_ptr<char[]>(new char[strlen(other.bugDetails.get()) + 1]);
        strcpy(this->bugDetails.get(), other.bugDetails.get());
    }
    return *this;
}

BugFixCommit& BugFixCommit::operator=(BugFixCommit&& other) noexcept {
    if (this != &other) {
        Commit::operator=(std::move(other));
        this->bugDetails = other.bugDetails;
        other.bugDetails = nullptr;
    }
    return *this;
}

bool BugFixCommit::operator==(const BugFixCommit& other) const {
    return Commit::operator==(other) && (strcmp(this->bugDetails.get(), other.bugDetails.get()) == 0);
}

bool BugFixCommit::operator!=(const BugFixCommit& other) const {
    return !(*this == other);
}

void BugFixCommit::setBugDetails(const char* details) {
    this->bugDetails = std::shared_ptr<char[]>(new char[strlen(details) + 1]);
    strcpy(this->bugDetails.get(), details); 
}

const char* BugFixCommit::getBugDetails() const {
    return this->bugDetails.get();
}

void BugFixCommit::display() const {
    std::lock_guard<std::mutex> lock(mutex); // Lock mutex
    std::cout<<"BugFixCommit: "<<"\n";
    std::cout<<"\tId: "<<this->getId()<<"\n";
    std::cout<<"\tMessage: ";
    auto sharedMessage = this->getMessage().lock(); // Convert to shared_ptr
    if (sharedMessage) {
        std::cout << sharedMessage.get() << "\n";
    } else {
        std::cout << "No message available\n";
    }
    std::cout<<"\tBug details: "<<this->bugDetails<<"\n";
}



