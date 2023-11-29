#include "MergeCommit.h"

using namespace MyGit;

MergeCommit::MergeCommit(const char* message, const char* mergeDetails) : Commit(message) {
    this->mergeDetails = std::shared_ptr<char[]>(new char[strlen(mergeDetails) + 1]);
    strcpy(this->mergeDetails.get(), mergeDetails);
}

MergeCommit::MergeCommit(const MergeCommit& other) : Commit(other) {
    this->mergeDetails = std::shared_ptr<char[]>(new char[strlen(other.mergeDetails.get()) + 1]);
    strcpy(this->mergeDetails.get(), other.mergeDetails.get());
}

MergeCommit::MergeCommit(MergeCommit&& other) noexcept : Commit(std::move(other)) {
    this->mergeDetails = other.mergeDetails;
    other.mergeDetails = nullptr;
}

MergeCommit::~MergeCommit() {
}

MergeCommit& MergeCommit::operator=(const MergeCommit& other) {
    if (this != &other) {
        Commit::operator=(other);
        this->mergeDetails = std::shared_ptr<char[]>(new char[strlen(other.mergeDetails.get()) + 1]);
        strcpy(this->mergeDetails.get(), other.mergeDetails.get());
    }
    return *this;
}

MergeCommit& MergeCommit::operator=(MergeCommit&& other) noexcept {
    if (this != &other) {
        Commit::operator=(std::move(other));
        this->mergeDetails = other.mergeDetails;
        other.mergeDetails = nullptr;
    }
    return *this;
}

bool MergeCommit::operator==(const MergeCommit& other) const {
    return Commit::operator==(other) && (strcmp(this->mergeDetails.get(), other.mergeDetails.get()) == 0);
}

bool MergeCommit::operator!=(const MergeCommit& other) const {
    return !(*this == other);
}

void MergeCommit::setMergeDetails(const char* details) {
    this->mergeDetails = std::shared_ptr<char[]>(new char[strlen(details) + 1]);
    strcpy(this->mergeDetails.get(), details); 
}

const char* MergeCommit::getMergeDetails() const {
    return this->mergeDetails.get();
}

void MergeCommit::display() const {
    std::lock_guard<std::mutex> lock(mutex);
    std::cout<<"MergeCommit: "<<"\n";
    std::cout<<"\tId: "<<this->getId()<<"\n";
     std::cout<<"\tMessage: ";
    auto sharedMessage = this->getMessage().lock(); // Convert to shared_ptr
    if (sharedMessage) {
        std::cout << sharedMessage.get() << "\n"; 
    } else {
        std::cout << "No message available\n";
    }
    std::cout<<"\tMerge details: "<<this->mergeDetails<<"\n";
}
