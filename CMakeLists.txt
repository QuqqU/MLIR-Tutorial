# For a better template to copy, see examples/standalone
add_subdirectory(include)

set(LLVM_LINK_COMPONENTS
  Support
  )

add_toy_chapter(toyc-ch1
  toyc.cpp
  src/AST.cpp
  src/ToyDialect.cpp
  src/ToyOps.cpp
  src/MLIRGen.cpp


  DEPENDS
  ToyCh1OpsIncGen

  )
include_directories(include/)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/)
target_link_libraries(toyc-ch1
  PRIVATE
    MLIRAnalysis
    MLIRIR
    MLIRParser
    MLIRSideEffectInterfaces
    MLIRTransforms)


# add_subdirectory(include)

# # For a better template to copy, see examples/standalone
# set(LLVM_LINK_COMPONENTS
#     Support
# )

# # macro(add_toy_chapter name)
# # add_dependencies(Toy ${name})
# # add_llvm_example(${name} ${ARGN})
# # endmacro(add_toy_chapter name)
# add_toy_chapter(toyc-ch1
#     toyc.cpp
#     src/AST.cpp
# )

# include_directories(include/)
# include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/)

# target_link_libraries(toyc-ch1
#     PRIVATE
#     MLIRAnalysis
#     MLIRIR
#     MLIRParser
#     MLIRSideEffectInterfaces
#     MLIRTransforms
#     MLIRSupport)
