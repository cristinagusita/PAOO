#pragma once
#include "IVersionControl.h"
#include <string>
#include <thread>
#include <semaphore>
#include <barrier>
#include <memory>
#include <mutex>

namespace MyGit {
    class Commit : public IVersionControlObject {
        protected:
            static int idCounter;
            int id;   
            std::shared_ptr<char[]> message; // Use shared_ptr for message

        public:
            Commit(const char* message);
            Commit(const Commit& other);
            Commit(Commit&& other) noexcept;
            virtual ~Commit();
            Commit& operator=(const Commit&);
            Commit& operator=(Commit&&) noexcept;
            bool operator==(const Commit&) const;
            bool operator!=(const Commit&) const;
            int getId() const override;
            std::weak_ptr<char[]> getMessage() const override; // Return weak_ptr to prevent ownership issues
            void exampleModifyMessage();

            // Thread synchronization
            static std::mutex mutex;
        };
}
