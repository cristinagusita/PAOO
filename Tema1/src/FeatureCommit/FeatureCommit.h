#include "Commit.h"
#include <iostream>
#include <cstring>

namespace MyGit {
    class FeatureCommit : public Commit {
    private:
        char* featureDetails;
    public:
        FeatureCommit(const char*, const char*);
        FeatureCommit(const FeatureCommit&);
        FeatureCommit(FeatureCommit&&) noexcept;
        ~FeatureCommit();
        FeatureCommit& operator=(const FeatureCommit&);
        FeatureCommit& operator=(FeatureCommit&&) noexcept;
        bool operator==(const FeatureCommit&) const;
        bool operator!=(const FeatureCommit&) const;
        void setFeatureDetails(const char* details);
        const char* getFeatureDetails() const;
        virtual void display() const override;
    };
}
