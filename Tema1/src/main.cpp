#include "Commit.h"
#include "Repository.h"
#include <iostream>

int main() {
    Repository repo;

    Commit c1(1, "Initial commit", 42);
    Commit c2(2, "Added new feature", 84);
    Commit c3(3, "Bug fixes and improvements :)", 16);

    repo.addCommit(c1);
    repo.addCommit(c2);
    repo.addCommit(c3);

    c2.exampleModifyMessage();

    Commit found = repo.getCommitById(2);
    std::cout << "Commit Message after modification: " << c2.getMessage() << "\n";
    std::cout << "Commit Message: " << found.getMessage() << "\n";
    std::cout << "Commit Data: " << found.getData() << "\n";

    return 0;
}
