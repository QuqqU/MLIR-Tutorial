//===- ToyCombine.cpp - Toy High Level Optimizer --------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements a set of simple combiners for optimizing operations in
// the Toy dialect.
//
//===----------------------------------------------------------------------===//

#include "toy/dialect/ToyOps.h"
#include "toy/dialect/ToyDialect.h"
#include "mlir/IR/OpImplementation.h"
using namespace mlir;
using namespace toy;

// / Infer the output shape of the AddOp, this is required by the shape inference
// / interface.
void AddOp::inferShapes() { getResult().setType(getOperand(0).getType()); }

// / Infer the output shape of the MulOp, this is required by the shape inference
// / interface.
void MulOp::inferShapes() { getResult().setType(getOperand(0).getType()); }

void TransposeOp::inferShapes() {
  auto arrayTy = getOperand().getType().cast<RankedTensorType>();
  SmallVector<int64_t, 2> dims(llvm::reverse(arrayTy.getShape()));
  getResult().setType(RankedTensorType::get(dims, arrayTy.getElementType()));
}

// / Infer the output shape of the CastOp, this is required by the shape
// / inference interface.
void CastOp::inferShapes() { getResult().setType(getOperand().getType()); }
