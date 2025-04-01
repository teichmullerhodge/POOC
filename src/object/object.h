#ifndef OBJECT_H
#define OBJECT_H
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/// simple alias for struct.
#define class struct
/// simple alias for typedef struct
#define classdef typedef struct
/// simple rule for distinguish between class methods
/// and normal functions.
#define extends(class)

#define declare(self, method) self->method = method

#define omit(self, method) self->method = NULL

#define fn(signature) (*signature)

inline void assert_encapsulation(bool condition, const char *message) {
  if (!condition) {
    fprintf(stderr, "Error: %s\n", message);
    abort();
  }
}

#define instanceof(method)                                                     \
  assert_encapsulation(self->method != NULL, "Method is private")

#endif // !OBJECT_H