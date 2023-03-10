# For a better template to copy, see examples/standalone
include_directories(include)
add_subdirectory(include)

set(LLVM_LINK_COMPONENTS
    Support
)

set(LLVM_TARGET_DEFINITIONS src/pass/CanonicalizerPass/ReshapeOptPattern.td)
mlir_tablegen(ReshapeOptPattern.inc -gen-rewriters)
add_public_tablegen_target(ReshapeOptPatternIncGen)

add_toy_chapter(toyc-ch1
    toyc.cpp

    src/dialect/ToyDialect.cpp
    src/dialect/ToyOps.cpp
    src/parser/AST.cpp

    src/pass/CanonicalizerPass/RegisterPattern.cpp
    src/pass/InlinerPass/InlineOpImpl.cpp
    src/pass/InlinerPass/ToyInlinerImpl.cpp
    src/pass/ShapeInferencePass/ShapeInferenceOpImpl.cpp
    src/pass/ShapeInferencePass/ShapeInferencePass.cpp
    src/pass/LowerToAffinePass/LowerToAffinePass.cpp

    src/MLIRGen.cpp

    DEPENDS

    ToyCh1OpsIncGen
    ReshapeOptPatternIncGen
    ToyCh1ShapeInferenceInterfaceIncGen
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/)
get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
target_link_libraries(toyc-ch1
    PRIVATE

    ${dialect_libs}
    MLIRAnalysis
    MLIRCallInterfaces
    MLIRCastInterfaces
    MLIRIR
    MLIRParser
    MLIRPass
    MLIRSideEffectInterfaces
    MLIRSupport
    MLIRTransforms)
