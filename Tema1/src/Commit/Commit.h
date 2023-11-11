#pragma once
#include "IVersionControl.h"
#include <string>

namespace MyGit {
    class Commit : public IVersionControlObject {
        protected:
            static int idCounter;
            int id;   
            char* message;

        public:
            Commit(const char* message);
            Commit(const Commit& other); 
            Commit(Commit&& other) noexcept; 
            virtual ~Commit();
            Commit& operator=(const Commit&);
            Commit& operator=(Commit&&) noexcept;
            bool operator==(const Commit&) const;
            bool operator!=(const Commit&) const;
            int getId() const;
            char* getMessage() const;
            void exampleModifyMessage();

        };
}
