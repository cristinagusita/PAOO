#include "Commit.h"
#include <iostream>
#include <cstring>

namespace MyGit {

    class MergeCommit : public Commit {
    private:
         std::shared_ptr<char[]> mergeDetails;
    public:
        MergeCommit(const char*, const char*);
        MergeCommit(const MergeCommit&);
        MergeCommit(MergeCommit&&) noexcept;
        ~MergeCommit();
        MergeCommit& operator=(const MergeCommit&);
        MergeCommit& operator=(MergeCommit&&) noexcept;
        bool operator==(const MergeCommit&) const;
        bool operator!=(const MergeCommit&) const;
        void setMergeDetails(const char* details);
        const char* getMergeDetails() const;
        virtual void display() const override;
    };
}