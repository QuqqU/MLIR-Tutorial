# For a better template to copy, see examples/standalone
include_directories(include)
add_subdirectory(include)

set(LLVM_LINK_COMPONENTS
    Support
)

set(LLVM_TARGET_DEFINITIONS src/pass/combine/ReshapeOptPattern.td)
mlir_tablegen(ReshapeOptPattern.inc -gen-rewriters)
add_public_tablegen_target(ToyCh1CombineIncGen)

add_toy_chapter(toyc-ch1
    toyc.cpp
    src/parser/AST.cpp
    src/dialect/ToyDialect.cpp
    src/dialect/ToyOps.cpp
    src/dialect/interface/ToyInlinerInterface.cpp
    src/MLIRGen.cpp
    src/pass/combine/ToyCombine.cpp

    DEPENDS

    ToyCh1OpsIncGen
    ToyCh1CombineIncGen
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
# Support
# )

# # macro(add_toy_chapter name)
# # add_dependencies(Toy ${name})
# # add_llvm_example(${name} ${ARGN})
# # endmacro(add_toy_chapter name)
# add_toy_chapter(toyc-ch1
# toyc.cpp
# src/AST.cpp
# )

# include_directories(include/)
# include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/)

# target_link_libraries(toyc-ch1
# PRIVATE
# MLIRAnalysis
# MLIRIR
# MLIRParser
# MLIRSideEffectInterfaces
# MLIRTransforms
# MLIRSupport)
