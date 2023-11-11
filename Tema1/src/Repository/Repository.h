#pragma once
#include <vector>
#include "Commit.h"

namespace MyGit {

class Repository {
    private:
        std::vector<Commit*> commits;

    public:
        Repository();
        ~Repository();
        void addCommit(Commit* commit);
        const Commit* getCommitById(int id) const;
        std::vector<Commit*> getCommits() const;
    };

}