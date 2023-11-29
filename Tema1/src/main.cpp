#include "Commit.h"
#include "FeatureCommit.h"
#include "BugFixCommit.h"
#include "MergeCommit.h"
#include "Repository.h"
#include <iostream>

using MyGit::Repository;
using MyGit::Commit;
using MyGit::FeatureCommit;
using MyGit::BugFixCommit;
using MyGit::MergeCommit;

int main() {
    Repository rep;

    // Create threads for each addCommit
    std::thread thread1([&rep]() {
        rep.addCommit(std::make_shared<FeatureCommit>("Add new feature", "Add new feature details"));
    });

    std::thread thread2([&rep]() {
        rep.addCommit(std::make_shared<BugFixCommit>("Fix bug", "Fix bug details"));
    });

    std::thread thread3([&rep]() {
        rep.addCommit(std::make_shared<MergeCommit>("Merge branch", "Merge branch details"));
    });

    // Wait for the threads to finish
    thread1.join();
    thread2.join();
    thread3.join();


    auto featureCommitPtr = rep.getCommitById(1);
    if (featureCommitPtr) {
        auto featureCommitMessage = featureCommitPtr->getMessage().lock(); // Lock weak_ptr to shared_ptr
        if (featureCommitMessage) {
            std::cout << featureCommitMessage.get() << "\n"; // Access the message
        } else {
            std::cout << "No message available." << "\n";
        }
    } else {
        std::cout << "Commit with ID 0 not found." << "\n";
    }



    rep.processCommitsInParallel();
    

    return 0;
}
