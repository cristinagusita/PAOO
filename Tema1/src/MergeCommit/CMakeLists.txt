add_library(MergeCommit MergeCommit.cpp)
target_link_libraries(MergeCommit PUBLIC Commit)
target_include_directories(MergeCommit 
 PUBLIC
  ../Commit/
)