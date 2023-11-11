#include "Repository.h"
#include<iostream>

MyGit::Repository::Repository(){
    std::cout<<"I am the repo constructor!"<<"\n";
}

MyGit::Repository::~Repository() {
    std::cout<<"I am the repo destructor!"<<"\n";
}

void MyGit::Repository::addCommit(Commit* commit) {
    std::cout<<"Adding commit"<<"\n";
    commits.push_back(commit);
}

const MyGit::Commit* MyGit::Repository::getCommitById(int id) const {
    for (auto commit : commits) {
        if (commit->getId() == id) {
            return commit;
        }
    }
    return nullptr; 
}

std::vector<MyGit::Commit*> MyGit::Repository::getCommits() const {
    return commits;
}