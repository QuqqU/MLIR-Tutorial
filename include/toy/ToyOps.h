#ifndef MLIR_TUTORIAL_TOY_OPS_H_
#define MLIR_TUTORIAL_TOY_OPS_H_

#include "mlir/IR/Dialect.h"
#include "mlir/IR/FunctionInterfaces.h"
#include "mlir/IR/SymbolTable.h"
#include "mlir/Interfaces/CallInterfaces.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

/// Include the auto-generated header file containing the declarations of the
/// toy operations.
#define GET_OP_CLASSES
#include "toy/ToyOps.h.inc"

#endif // MLIR_TUTORIAL_TOY_OPS_H_
