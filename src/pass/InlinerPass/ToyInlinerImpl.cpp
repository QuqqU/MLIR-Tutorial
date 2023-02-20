#include "toy/interface/inline/InlinerInterface.h"
#include "toy/dialect/ToyDialect.h"
#include "toy/dialect/ToyOps.h"

// #include "mlir/IR/Builders.h"
// #include "mlir/IR/BuiltinTypes.h"
// #include "mlir/IR/FunctionImplementation.h"
// #include "mlir/IR/OpImplementation.h"
// #include "mlir/Transforms/InliningUtils.h"

namespace mlir {
namespace toy {

//===--------------------------------------------------------------------===//
// Analysis Hooks
//===--------------------------------------------------------------------===//

/// All call operations within toy can be inlined.
bool InlinerInterface::isLegalToInline(Operation *call, Operation *callable,
                                          bool wouldBeCloned) const {
  return true;
}

/// All operations within toy can be inlined.
bool InlinerInterface::isLegalToInline(Operation *, Region *, bool,
                                          IRMapping &) const {
  return true;
}

// All functions within toy can be inlined.
bool InlinerInterface::isLegalToInline(Region *, Region *, bool,
                                          IRMapping &) const {
  return true;
}

//===--------------------------------------------------------------------===//
// Transformation Hooks
//===--------------------------------------------------------------------===//

/// Handle the given inlined terminator(toy.return) by replacing it with a new
/// operation as necessary.
void InlinerInterface::handleTerminator(Operation *op,
                                           ArrayRef<Value> valuesToRepl) const {
  // Only "toy.return" needs to be handled here.
  auto returnOp = cast<ReturnOp>(op);

  // Replace the values directly with the return operands.
  assert(returnOp.getNumOperands() == valuesToRepl.size());
  for (const auto &it : llvm::enumerate(returnOp.getOperands()))
    valuesToRepl[it.index()].replaceAllUsesWith(it.value());
}

/// Attempts to materialize a conversion for a type mismatch between a call
/// from this dialect, and a callable region. This method should generate an
/// operation that takes 'input' as the only operand, and produces a single
/// result of 'resultType'. If a conversion can not be generated, nullptr
/// should be returned.

Operation *
InlinerInterface::materializeCallConversion(OpBuilder &builder, Value input,
                                               Type resultType,
                                               Location conversionLoc) const {
  return builder.create<CastOp>(conversionLoc, resultType, input);
}

} // namespace toy
} // namespace mlir