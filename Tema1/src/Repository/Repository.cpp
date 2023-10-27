#include "Repository.h"
#include<iostream>

Repository::Repository(){
    std::cout<<"I am the repo constructor!"<<"\n";
}

Repository::~Repository() {
    std::cout<<"I am the repo destructor!"<<"\n";
}

void Repository::addCommit(const Commit& commit) {
    std::cout<<"Adding commit"<<"\n";
    commits.push_back(commit);
}

Commit Repository::getCommitById(int id) const {
    for (const auto& commit : commits) {
        if (commit.getId() == id) {
            return commit;
        }
    }
    return Commit(-1, "", 0);
}
