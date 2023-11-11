#include "FeatureCommit.h"

using namespace MyGit;

FeatureCommit::FeatureCommit(const char* message, const char* featureDetails) : Commit(message) {
    this->featureDetails = new char[strlen(featureDetails) + 1];
    strcpy(this->featureDetails, featureDetails);
}

FeatureCommit::FeatureCommit(const FeatureCommit& other) : Commit(other) {
    this->featureDetails = new char[strlen(other.featureDetails) + 1];
    strcpy(this->featureDetails, other.featureDetails);
}

FeatureCommit::FeatureCommit(FeatureCommit&& other) noexcept : Commit(std::move(other)) {
    this->featureDetails = other.featureDetails;
    other.featureDetails = nullptr;
}

FeatureCommit::~FeatureCommit() {
    delete[] this->featureDetails;
}

FeatureCommit& FeatureCommit::operator=(const FeatureCommit& other) {
    if (this != &other) {
        Commit::operator=(other);
        delete[] this->featureDetails;
        this->featureDetails = new char[strlen(other.featureDetails) + 1];
        strcpy(this->featureDetails, other.featureDetails);
    }
    return *this;
}

FeatureCommit& FeatureCommit::operator=(FeatureCommit&& other) noexcept {
    if (this != &other) {
        Commit::operator=(std::move(other));
        delete[] this->featureDetails;
        this->featureDetails = other.featureDetails;
        other.featureDetails = nullptr;
    }
    return *this;
}

bool FeatureCommit::operator==(const FeatureCommit& other) const {
    return Commit::operator==(other) && (strcmp(this->featureDetails, other.featureDetails) == 0);
}

bool FeatureCommit::operator!=(const FeatureCommit& other) const {
    return !(*this == other);
}


void FeatureCommit::setFeatureDetails(const char* details) {
    this->featureDetails = new char[strlen(details) + 1];
    strcpy(this->featureDetails, details); 
}

const char* FeatureCommit::getFeatureDetails() const {
    return this->featureDetails;
}

void FeatureCommit::display() const {
    std::cout<<"FeatureCommit: "<<"\n";
    std::cout<<"\tId: "<<this->getId()<<"\n";
    std::cout<<"\tMessage: "<<this->getMessage()<<"\n";
    std::cout<<"\tFeature commit details: "<<this->featureDetails<<"\n";
}

