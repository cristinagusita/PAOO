add_library(Repository Repository.cpp)

target_include_directories(Repository 
 PUBLIC
  ../Commit/
)
