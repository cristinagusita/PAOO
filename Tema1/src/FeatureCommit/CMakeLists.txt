add_library(FeatureCommit FeatureCommit.cpp)
target_link_libraries(FeatureCommit PUBLIC Commit)
target_include_directories(FeatureCommit 
 PUBLIC
  ../Commit/
)