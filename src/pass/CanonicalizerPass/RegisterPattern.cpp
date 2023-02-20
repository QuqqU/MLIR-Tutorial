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
#include "mlir/IR/Matchers.h"
#include "mlir/IR/PatternMatch.h"
#include "toy/dialect/ToyOps.h"
#include <numeric>
using namespace mlir;
using namespace toy;

/// Register our patterns as "canonicalization" patterns on the TransposeOp so
/// that they can be picked up by the Canonicalization framework.
namespace {
#include "SimplifyTransposePattern.cpp"
}
void TransposeOp::getCanonicalizationPatterns(RewritePatternSet &results,
                                              MLIRContext *context) {
  results.add<SimplifyTransposePattern>(context);
}

// /// Register our patterns as "canonicalization" patterns on the ReshapeOp so
// /// that they can be picked up by the Canonicalization framework.
namespace {
/// Include the patterns defined in the Declarative Rewrite framework.
#include "ReshapeOptPattern.inc"
} // namespace
void ReshapeOp::getCanonicalizationPatterns(RewritePatternSet &results,
                                            MLIRContext *context) {
  results.add<ReshapeReshapeOptPattern, RedundantReshapeOptPattern,
              FoldConstantReshapeOptPattern>(context);
}
