#pragma once
#include <string>

namespace MyGit {
    class Commit {
        private:
            int id;
            char* message;
            int data; 

        public:
            Commit(int id, const char* message, int data);
            Commit(const Commit& other); 
            Commit(Commit&& other) noexcept; 
            ~Commit();
            MyGit::Commit& MyGit::Commit::operator=(const Commit&);
            MyGit::Commit& MyGit::Commit::operator=(Commit&&);
            bool MyGit::Commit::operator==(const Commit&) const;
            bool MyGit::Commit::operator!=(const Commit&) const;
            int getId() const;
            char* getMessage() const;
            int getData() const;
            void exampleModifyMessage();

        };
}


