#include "Commit.h"
#include <iostream>
#include <cstring>

namespace MyGit {

    class BugFixCommit : public Commit {
    private:
        char* bugDetails;
    public:
        BugFixCommit(const char*, const char*);
        BugFixCommit(const BugFixCommit&);
        BugFixCommit(BugFixCommit&&) noexcept;
        ~BugFixCommit();
        BugFixCommit& operator=(const BugFixCommit&);
        BugFixCommit& operator=(BugFixCommit&&) noexcept;
        bool operator==(const BugFixCommit&) const;
        bool operator!=(const BugFixCommit&) const;
        void setBugDetails(const char* details);
        const char* getBugDetails() const;
        virtual void display() const override;
    };

}
