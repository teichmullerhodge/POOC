#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
/// simple alias for struct.
#define class struct
/// simple alias for typedef struct
#define classdef typedef struct
/// simple rule for distinguish between class methods
/// and normal functions.
#define extends(class)

#define declare(self, method) self->method = method;

#endif // !OBJECT_H