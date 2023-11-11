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

    Commit* featureCommit = new FeatureCommit("Added a new feature", "The feature X now manages to blablabla");

    Commit* bugCommit = new BugFixCommit("Solved a bug", "This bug fix blablabla");

    Commit* mergeCommit = new MergeCommit("Merged feature X with master", "This merge commit blablabla");

    rep.addCommit(featureCommit);
    rep.addCommit(bugCommit);
    rep.addCommit(mergeCommit);

    for (auto commit : rep.getCommits()) {
        commit->display();
    }
    

    return 0;
}
