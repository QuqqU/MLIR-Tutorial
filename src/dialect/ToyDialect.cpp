//===- Dialect.cpp - Toy IR Dialect registration in MLIR ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the dialect for the Toy IR: custom type parsing and
// operation verification.
//
//===----------------------------------------------------------------------===//

#include "toy/dialect/ToyDialect.h"
#include "toy/dialect/ToyOps.h"


using namespace mlir;
using namespace mlir::toy;


//===----------------------------------------------------------------------===//
// ToyDialect
//===----------------------------------------------------------------------===//

#include "toy/dialect/ToyDialect.cpp.inc"

/// Dialect initialization, the instance will be owned by the context. This is
/// the point of registration of types and operations for the dialect.
void ToyDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "toy/dialect/ToyOps.cpp.inc"
      >();
}
