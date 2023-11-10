#pragma once
#include <vector>
#include "Commit.h"

namespace MyGit {

class Repository {
    private:
        std::vector<Commit> commits;

    public:
        Repository();
        ~Repository();
        void addCommit(const Commit& commit);
        Commit getCommitById(int id) const;
    };

}

