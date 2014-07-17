#include "IR.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include "Types.h"

using namespace simit;
using namespace std;

/* Tensor */
Tensor::~Tensor() {
  delete type;
}


/* DenseTensorLiteral */
DenseLiteralTensor::DenseLiteralTensor(const TensorType *type, void *data)
: LiteralTensor(type) {
  auto componentSize = TensorType::componentSize(type->getComponentType());
  auto dataSize = type->getSize() * componentSize;
  this->data = malloc(dataSize);
  memcpy(this->data, data, dataSize);
}

DenseLiteralTensor::~DenseLiteralTensor() {
  free(data);
}

DenseLiteralTensor::operator std::string() const {
  string result;
  if (name != "") {
    result += name + " : " + string(*type) + " = ";
  }

  // TODO: Add nicer value printing that prints matrices and tensors
  switch (type->getComponentType()) {
    case TensorType::INT: {
      int *idata = (int*)data;
      if (type->getSize() == 1) {
        result += to_string(idata[0]);
      }
      else {
        result += "[";
        result += to_string(idata[0]);
        for (unsigned int i=0; i<type->getSize(); ++i) {
          result += ", " + to_string(idata[i]);
        }
        result += "]";
      }
      break;
    }
    case TensorType::FLOAT: {
      double *fdata = (double*)data;
      if (type->getSize() == 1) {
        result += to_string(fdata[0]);
      }
      else {
        result += "[";
        result += to_string(fdata[0]);
        for (unsigned int i=0; i<type->getSize(); ++i) {
          result += ", " + to_string(fdata[i]);
        }
        result += "]";
      }
      break;
    }
  }
//  result += to_string(type->getOrder());
  return result;
}


/* Function */
Function::Function() {}

Function::~Function() {}

Function::operator std::string() const {
  return "Function";
}