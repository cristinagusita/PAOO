#include "Repository.h"
#include <iostream>

MyGit::Repository::Repository() : sem(1), commitProcessingBarrier(3) {
    std::cout<<"I am the repo constructor!"<<"\n";
}

MyGit::Repository::~Repository() {
    std::cout<<"I am the repo destructor!"<<"\n";
}

void MyGit::Repository::addCommit(std::shared_ptr<Commit> commit) {
    sem.acquire();
    std::cout << "Adding commit" << "\n";
    commits.push_back(std::move(commit)); 
    sem.release();
}


std::shared_ptr<MyGit::Commit> MyGit::Repository::getCommitById(int id) const {
    for (const auto& commit : commits) {
        if (commit->getId() == id) {
            return commit;
        }
    }
    return nullptr; 
}


std::vector<std::shared_ptr<MyGit::Commit>> MyGit::Repository::getCommits() const {
    return commits;
}

void MyGit::Repository::processCommitsInParallel() {
    // Store threads to join later
    std::vector<std::thread> threads;

    for (auto& commit : commits) {
        threads.emplace_back([this, &commit]() {

            std::cout << "Processing first part of commit ID: " << commit->getId() << std::endl;
            
            commit->display();

            commitProcessingBarrier.arrive_and_wait();
            
            std::cout << "Processing second part of commit ID: " << commit->getId() << std::endl;
           
        });
    }

    // Join all threads
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

}