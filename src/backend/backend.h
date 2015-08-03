#ifndef SIMIT_BACKEND_H
#define SIMIT_BACKEND_H

#include <vector>
#include <map>

#include "uncopyable.h"
#include "function.h"

namespace simit {
class Diagnostics;

namespace ir {
class Func;
}

namespace internal {
class ProgramContext;

/// Code generators are used to turn Simit IR into some other representation.
/// Examples include LLVM IR, compiled machine code and Graphviz .dot files.
class Backend : simit::interfaces::Uncopyable {
public:
  Backend() {}
  virtual ~Backend() {}

  // TODO: Change to simply return a Function object (not pointer)
  virtual simit::internal::Function *compile(simit::ir::Func func) = 0;
};

}}
#endif