add_library(BugFixCommit BugFixCommit.cpp)
target_link_libraries(BugFixCommit PUBLIC Commit)
target_include_directories(BugFixCommit 
 PUBLIC
  ../Commit/
)