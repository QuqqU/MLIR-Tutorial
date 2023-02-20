#ifndef MLIR_TUTORIAL_TOY_DIALECT_INTERFACE_H_
#define MLIR_TUTORIAL_TOY_DIALECT_INTERFACE_H_

// #include "toy/dialect/ToyDialect.h"

// // #include "mlir/IR/Builders.h"
// // #include "mlir/IR/BuiltinTypes.h"
// // #include "mlir/IR/FunctionImplementation.h"
// // #include "mlir/IR/OpImplementation.h"
#include "mlir/Transforms/InliningUtils.h"

namespace mlir {
namespace toy {

//===----------------------------------------------------------------------===//
// ToyInlinerInterface
//===----------------------------------------------------------------------===//

/// This class defines the interface for handling inlining with Toy
/// operations.
struct InlinerInterface : public DialectInlinerInterface {
  using DialectInlinerInterface::DialectInlinerInterface;

  //===--------------------------------------------------------------------===//
  // Analysis Hooks
  //===--------------------------------------------------------------------===//

  /// All call operations within toy can be inlined.
  bool isLegalToInline(Operation *call, Operation *callable,
                       bool wouldBeCloned) const final;

  /// All operations within toy can be inlined.
  bool isLegalToInline(Operation *, Region *, bool, IRMapping &) const final;

  // All functions within toy can be inlined.
  bool isLegalToInline(Region *, Region *, bool, IRMapping &) const final;

  //===--------------------------------------------------------------------===//
  // Transformation Hooks
  //===--------------------------------------------------------------------===//

  /// Handle the given inlined terminator(toy.return) by replacing it with a new
  /// operation as necessary.
  void handleTerminator(Operation *op,
                        ArrayRef<Value> valuesToRepl) const final;

  /// Attempts to materialize a conversion for a type mismatch between a call
  /// from this dialect, and a callable region. This method should generate an
  /// operation that takes 'input' as the only operand, and produces a single
  /// result of 'resultType'. If a conversion can not be generated, nullptr
  /// should be returned.
  Operation *materializeCallConversion(OpBuilder &builder, Value input,
                                       Type resultType,
                                       Location conversionLoc) const final;
};

} // namespace toy
} // namespace mlir

#endif // MLIR_TUTORIAL_TOY_DIALECT_INTERFACE_H_