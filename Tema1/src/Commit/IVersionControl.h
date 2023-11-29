#pragma once
#include <memory>

namespace MyGit {
    class IVersionControlObject {
    public:
        virtual int getId() const = 0;
        virtual std::weak_ptr<char[]> getMessage() const = 0;
        virtual void display() const = 0; 
    };
}
