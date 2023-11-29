#include "FeatureCommit.h"

using namespace MyGit;

FeatureCommit::FeatureCommit(const char* message, const char* featureDetails) : Commit(message) {
    this->featureDetails = std::shared_ptr<char[]>(new char[strlen(featureDetails) + 1]);
    strcpy(this->featureDetails.get(), featureDetails);
}

FeatureCommit::FeatureCommit(const FeatureCommit& other) : Commit(other) {
    this->featureDetails = std::shared_ptr<char[]>(new char[strlen(other.featureDetails.get()) + 1]);
    strcpy(this->featureDetails.get(), other.featureDetails.get());
}

FeatureCommit::FeatureCommit(FeatureCommit&& other) noexcept : Commit(std::move(other)) {
    this->featureDetails = other.featureDetails;
    other.featureDetails = nullptr;
}

FeatureCommit::~FeatureCommit() {
}

FeatureCommit& FeatureCommit::operator=(const FeatureCommit& other) {
    if (this != &other) {
        Commit::operator=(other);
        this->featureDetails = std::shared_ptr<char[]>(new char[strlen(other.featureDetails.get()) + 1]);
        strcpy(this->featureDetails.get(), other.featureDetails.get());
    }
    return *this;
}

FeatureCommit& FeatureCommit::operator=(FeatureCommit&& other) noexcept {
    if (this != &other) {
        Commit::operator=(std::move(other));
        this->featureDetails = other.featureDetails;
        other.featureDetails = nullptr;
    }
    return *this;
}

bool FeatureCommit::operator==(const FeatureCommit& other) const {
    return Commit::operator==(other) && (strcmp(this->featureDetails.get(), other.featureDetails.get()) == 0);
}

bool FeatureCommit::operator!=(const FeatureCommit& other) const {
    return !(*this == other);
}


void FeatureCommit::setFeatureDetails(const char* details) {
    this->featureDetails = std::shared_ptr<char[]>(new char[strlen(details) + 1]);
    strcpy(this->featureDetails.get(), details); 
}

const char* FeatureCommit::getFeatureDetails() const {
    return this->featureDetails.get();
}

void FeatureCommit::display() const {
    std::lock_guard<std::mutex> lock(mutex);
    std::cout<<"FeatureCommit: "<<"\n";
    std::cout<<"\tId: "<<this->getId()<<"\n";
     std::cout<<"\tMessage: ";
    auto sharedMessage = this->getMessage().lock(); // Convert to shared_ptr
    if (sharedMessage) {
        std::cout << sharedMessage.get() << "\n";
    } else {
        std::cout << "No message available\n";
    }
    std::cout<<"\tFeature commit details: "<<this->featureDetails<<"\n";
}

