# Create a library from the Repository sources
add_library(Repository Repository.cpp)

# Include directories for this library (if necessary)
target_include_directories(Repository 
 PUBLIC
  ../Commit/
)
