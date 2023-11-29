#pragma once
#include <vector>
#include "Commit.h"


namespace MyGit {

class Repository {
    private:
        std::vector<std::shared_ptr<Commit>> commits;
        std::counting_semaphore<1> sem;
        std::barrier<> commitProcessingBarrier;
    public:
        Repository();
        ~Repository();
        void addCommit(std::shared_ptr<Commit> commit);
        std::shared_ptr<Commit> getCommitById(int id) const; 
        std::vector<std::shared_ptr<Commit>> getCommits() const;
        void processCommitsInParallel();

        static std::mutex mutex;
    };
}